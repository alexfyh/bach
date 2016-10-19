#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buscador_funcion.c"
#include "parseo.c"
#include "path.c"
//#include <sys/types.h>
#include <sys/wait.h>
//#include <stdbool.h>

int main(int argc, char *argv[])
{	
	char hostname [20];
	gethostname(hostname,20);
	char* user;
	user = getlogin();
	pid_t pid;
	int status;
	char comando[50]="";
	char *paths=cadena_path();
	int cant_paths=cantidad_cadenas(paths,':')+1;
	char *arreglo_path[cant_paths];
	asignador(paths,cant_paths,arreglo_path,":");
	bool espera=true;

	//printf("%s@%s:%s$ ", user, hostname,getcwd(NULL,50));

	while(1)

		{
			//printf("$");
			printf("%s@%s:%s$ ", user, hostname,getcwd(NULL,50));
			int i=0;

			char  ejecutar[125];
			fgets(ejecutar,124,stdin);
			argc=cantidad_cadenas(ejecutar,' ')+1;
			asignador(ejecutar,argc,argv," ");
			int ultimo=strlen(argv[argc-1]);
			*(argv[argc-1]+ultimo-1)='\0';
			// Verifica si al final hay un &
			if(strcmp(argv[argc-1],ampersand))
				{
				espera=true;
				printf("%s\n", "No es igual a &");
				}
			else
			{
				espera=false;
				printf("%s\n", "Igual a &");
				argv[argc-1]=NULL;
			}


			if(cmd_interno(argv))
			{
				//funcion(argc,comando,argumento1,argumento2);
			}
			else
			{
				
				pid=fork();
				if(pid==0)
					{
						//char *comando=argv[0];
						char *argumentos[argc+1];
						i=0;
						//printf("%s%s\n", argv[0],".");
						//printf("%s %s\n","Ejecutar: ",comando );
						//printf("%s\n","Con los siguientes argumentos: " );
						while(i<argc)				//verificar
						{
							argumentos[i]=argv[i];
							//printf("%s\n",argumentos[i] );
							i++;
						}
						argumentos[i]=NULL;			//necesario para el excev()
						//printf("%s%s\n","Ultimo argumento",argumentos[i] );
						sleep(5);
						ejecutable(argumentos,cant_paths,arreglo_path);
						//printf("%s\n", "Noooooooooooo");			//No se imprime por el cambio de excev()
						exit(0);
						//sleep(20);
						
					}
					else
					{
						if(pid>0)
						{
							if(espera)
							{
								printf("%s\n","Esperando al proceso hijo" );
								wait(&status);


							}

						//printf("%s@%s:%s$ ", user, hostname,getcwd(NULL,50));
						printf("%s\n","Luke,soy tu paaadreee");
						}
						else
						{
							printf("%s\n","La gran Rial" );
							 perror ("No se pudo crear proceso hijo");
						}
					}
			}
		}
return 0;
}