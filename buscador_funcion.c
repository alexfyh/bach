#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "comandos.c"

bool verificador_abs(char * path)
{
	if( access( path, F_OK ) != -1 )
	{
		printf("%s\n","Accesible" );
		return true;
	} 
	else 
	{
		printf("%s\n"," No accesible" );

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
				printf("%s\n", "Direccion actual");
				system("pwd");
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
			return false;
		}

	}
}

void ejecutable()
{
	if(*(argv[0])!='/')
	{
		//if()
		//printf("%s\n","No se definio para direcciones no absolutas todavia" );
		return false;
	}
	else
	{
		printf("%s\n","Direccion absoluta " );
		if(verificador_abs(argv[0]))
		{
			return true;
		}
		else
		{
			printf("%s\n",  "comando no existente");
			return false;
		}

	}


}