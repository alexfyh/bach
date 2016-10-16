#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lector_funcion.c"
#include "buscador_funcion.c"
#include "parseo.c"
#include "path.c"

int main(int argc, char *argv[])
{
	char comando[50]="";
	char argumento1[50];
	char argumento2[50];
	char path_act_abs[75];
	char *paths=cadena_path();
	int cant_paths=cantidad_cadenas(paths,':')+1;
	char * arreglo_path[cant_paths];
	asignador(paths,cant_paths,arreglo_path,":");

	while(1)

		{

			//Modificar el system
			//system("pwd");
			printf("$");
			char  ejecutar[125];
			fgets(ejecutar,124,stdin);
			argc=cantidad_cadenas(ejecutar,' ')+1;
			asignador(ejecutar,argc,argv," ");
/*
			if(analizador(argv))
			{
				//funcion(argc,comando,argumento1,argumento2);
			}
			else
			{
				printf("%s\n", "No paso analizador");
				//exit(0);
			}
			*/
			int i=0;
   while(i<argc)
   {
   		printf( "%d%s\n",i, argv[i] );
   		i++;
   }



				
		}

}