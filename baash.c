#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buscador_funcion.c"
#include "parseo.c"
#include "path.c"
//#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{	
	pid_t pid;
	int status;
	char comando[50]="";
	char *paths=cadena_path();
	int cant_paths=cantidad_cadenas(paths,':')+1;
	char *arreglo_path[cant_paths];
	asignador(paths,cant_paths,arreglo_path,":");

	while(1)

		{
			printf("$");

			int i;

			char  ejecutar[125];
			fgets(ejecutar,124,stdin);
			argc=cantidad_cadenas(ejecutar,' ')+1;
			asignador(ejecutar,argc,argv," ");
			int ultimo=strlen(argv[argc-1]);
			*(argv[argc-1]+ultimo-1)='\0';					//Necesario para cambiar \n por \0


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
						sleep(3);
						ejecutable(argumentos,cant_paths,arreglo_path);
						//printf("%s\n", "Noooooooooooo");			//No se imprime por el cambio de excev()
						exit(0);
						//sleep(20);
						
					}
					else
					{
						if(pid>0)
						{
						wait(&status);
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