#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lector_funcion.c"
#include "buscador_funcion.c"

int main(int argc, char *argv[])
{
	char comando[50]="";
	char argumento1[50];
	char argumento2[50];
	char path_act_abs[75];

	while(1)
	//while(strcmp(comando,salida)!=0)

		{
			//Modificar el system
			//system("pwd");
			printf("$");
			char  ejecutar[50];
			//redefinir tamano
			fgets(ejecutar,50,stdin);
			argc=sscanf(ejecutar,"%s %s %s",comando,argumento1,argumento2);
			argv[0]=comando;
			argv[1]=argumento1;
			argv[2]=argumento2;
			if(analizador(argv))
			{
				//funcion(argc,comando,argumento1,argumento2);
			}
			else
			{
				printf("%s\n", "No paso analizador");
				//exit(0);
			}
				
		}

	//printf("\n %s \n","Ha finalizado baash...Salu2");


}