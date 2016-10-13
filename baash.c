#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lector_funcion.c"
#include "buscador_funcion.c"

int main(int argc, char *argv[])
{
	char comando[30]="";
	char argumento1[10];
	char argumento2[10];
	char salida[]="exit";

	while(strcmp(comando,salida)!=0)

		{
			printf("$");
			char  ejecutar[50];
			
			fgets(ejecutar,30,stdin);
			argc=sscanf(ejecutar,"%s %s %s",comando,argumento1,argumento2);
			argv[0]=comando;
			argv[1]=argumento1;
			argv[2]=argumento2;
			if(analizador(comando))
			{
				funcion(argc,comando,argumento1,argumento2);
			}
			else
			{
				printf("%s\n", "No paso analizador");
			}
				
		}

	printf("\n %s \n","Ha finalizado baash...Salu2");


}