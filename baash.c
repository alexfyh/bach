#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buscador_funcion.c"
#include "parseo.c"
#include "path.c"
//#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

//#include <stdbool.h>

int main(int argc, char *argv[])
{	
	char hostname [20];
	gethostname(hostname,20);
	char* user;
	user = getlogin();
	//pid_t pid;
	int status;
	char comando[50]="";
	char *paths=cadena_path();
	int cant_paths=cantidad_cadenas(paths,':')+1;
	char *arreglo_path[cant_paths];
	asignador(paths,cant_paths,arreglo_path,":");
	bool espera=true;

	//printf("%s@%s:%s$ ", user, hostname,getcwd(NULL,50));
	pid_t id_padre;
	pid_t id_hijo;
	id_padre=getpid();
	char Buffer[124];
	int fd[2];
	while(1)

		{
			printf("%s@%s:%s$ ", user, hostname,getcwd(NULL,50));


			char  ejecutar[125];
			fgets(ejecutar,124,stdin);
			argc=cantidad_cadenas(ejecutar,' ')+1;
			asignador(ejecutar,argc,argv," ");
			int ultimo=strlen(argv[argc-1]);
			*(argv[argc-1]+ultimo-1)='\0';								//Le cambia el \n  por \0	

			if(cmd_interno(argv))
			{

			}
			else
			{
				// Operador >>>>>>>>>>>>>>>>>>>>
				if(strcmp(argv[argc-2],mayor)==0)
				{
					char * file=argv[argc-1];
					argv[argc-1]=NULL;
					argv[argc-2]=NULL;
					int destino_fichero;

					if(fork()==0)
					{
						
						destino_fichero = open (file, O_CREAT|O_APPEND|O_WRONLY, S_IWUSR|S_IRUSR);
						dup2 (destino_fichero, 1);
	    				close (destino_fichero);
						ejecutable(argv,cant_paths,arreglo_path);
	    				exit (1);
					}
					printf("%s\n","Despues del >>>>>>>" );

				}
				else
				{
					if(strcmp(argv[argc-2],menor)==0)
					{
						char * file=argv[argc-1];
						argv[argc-1]=NULL;
						argv[argc-2]=NULL;
						
						//printf("%d\n", origen_fichero);
						printf("%s\n", "<<<<<<<");
						if(fork()==0)
						{
							int origen_fichero=open(file,O_RDONLY,124);
							dup2(origen_fichero,0);
							close(origen_fichero);
							ejecutable(argv,cant_paths,arreglo_path);
						}
					}
					printf("%s\n","Despues de <<<<<<<" );


				}

				//Operador  &&&&&&&&&&&&&&&&&&&&&


			}
				printf("%s\n","Antes del &&&&&&&&" );
				if(strcmp(argv[argc-1],ampersand))
				{
					espera=true;
					//printf("%s\n", "No es igual a &");
				}
				else
				{
					espera=false;
					//printf("%s\n", "Igual a &");
					argv[argc-1]=NULL;

				}

				
				if ((id_hijo = fork ()) == 0)
					{
						//char *comando=argv[0];
						char *argumentos[argc+1];
						int i=0;
						while(i<argc)				//verificar
						{
							argumentos[i]=argv[i];
							i++;
						}
						argumentos[i]=NULL;			//necesario para el excev()
						//printf("%s%s\n","Ultimo argumento",argumentos[i] );
						sleep(5);
						ejecutable(argumentos,cant_paths,arreglo_path);
						exit(-1);
						
					}
					else
					{
						if(espera)
						{
							printf("%s\n","Esperando al proceso hijo" );
							while (waitpid (id_hijo, &status, 0) != id_hijo)
							{
								sleep(1);
							}
							//wait(&status);

						}

						//printf("%s@%s:%s$ ", user, hostname,getcwd(NULL,50));
						printf("%s\n","Luke,soy tu paaadreee");
						/*else
						{
							printf("%s\n","La gran Rial" );
							perror ("No se pudo crear proceso hijo");
						}*/
					}
			
			}
		
return 0;
}
