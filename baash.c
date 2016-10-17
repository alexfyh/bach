#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lector_funcion.c"
#include "buscador_funcion.c"
#include "parseo.c"
#include "path.c"
//#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{	
	int pid;
	int status;
	char comando[50]="";
//	char path_act_abs[75];
	char *paths=cadena_path();
	int cant_paths=cantidad_cadenas(paths,':')+1;
	char * arreglo_path[cant_paths];
	asignador(paths,cant_paths,arreglo_path,":");

	while(1)

		{

			//Modificar el system
			//system("pwd");
			printf("$");

			int i=0;

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
				if(pid>0)
					{
						wait(&status);
						printf("%s\n","Luke,soy tu paaadreee");
					}
					else
					{
						if(pid==0)
						{
							sleep(10);
							ejecutable(argv);
							printf("%s\n", "Noooooooooo");
						}
						else
						{
							printf("%s\n","La gran Rial" );
							 perror ("No se pudo crear proceso hijo");
						}
					}
			}
		}

}