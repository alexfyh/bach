#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "comandos.c"

void buscador_path(char * argumentos[], int cant_path,char * array_path[])
{
	int i=0;
	int estado;

	char  barra[2]="/";
	//printf("%s\n", barra);
	while(i<cant_path)
	{
		char direccion[strlen(array_path[i])+70];
		strcpy(direccion,array_path[i]);
		strcat(direccion,barra);
		strcat(direccion,argumentos[0]);		
		estado=execv(direccion,argumentos);
		//printf("%s\n", direccion);
		
		array_path[i]=direccion;
		i++;
		//direccion=strcat(direccion,array_path[i]);	
	}
	if(estado==-1)
	{
		printf("%s\n","No se encontro por path..." );
	}
}

bool verificador_abs(char * path)
{
	if( access( path, F_OK ) != -1 )
	{
		//printf("%s\n","Accesible" );
		return true;
	} 
	else 
	{
		//printf("%s\n"," No accesible" );

		return false;		
    }
}

bool cmd_interno(char **argv)
{

	if(strcmp(argv[0],salida)==0)
	{
		printf("\n %s \n","Ha finalizado baash...Salu2");
		exit(0);

	}
	else
	{
		if(strcmp(argv[0],cdir)==0)
		{
			if (chdir(argv[1])==0)
			{
				//printf("%s\n", "Direccion actual");
				//system("pwd");
				return true;

			}
			else
			{
				printf("%s\n", "Direccion no valida");
				return true;
			}
		}
		else
		{
			if(strcmp(argv[0],vacio)==0)
			{
				return true;
			}
			else
			{
				return false;				
			}

		}

	}
}

void ejecutable(char * argumentos[], int cant_path,char * array_path[])
{
	if((*(argumentos[0])=='/')|| (*(argumentos[0])=='.'))
	{
		int exito=execv(argumentos[0],argumentos);					//Si no se pudo ejecutar execv(), devuelve -1
		perror("Error en la ejecucion del comando... ");
		exit(exito);

	}

	else
	{
		
		buscador_path(argumentos,cant_path,array_path);
	}
}

