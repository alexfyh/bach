#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lector_funcion.c"

int main(int argc, char *argv[])
{
	//printf("%d\n",argc);
	char comando[30]="";
	char argumento1[10];
	char argumento2[10];
	char salida[]="exit";
	//int cant_arg;
	while(strcmp(comando,salida)!=0)

		{
			printf("$");
			char  ejecutar[50];
			
			fgets(ejecutar,30,stdin);
			argc=sscanf(ejecutar,"%s %s %s",comando,argumento1,argumento2);
			argv[0]=comando;
			argv[1]=argumento1;
			argv[2]=argumento2;
			funcion(argc,comando,argumento1,argumento2);
			//system(comando);
			//printf("%d\n %s %s %s \n",argc,argv[0],argv[1],argv[2] );		
		}



}