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

bool analizador(char **argv)
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
			//char path_actual[75];
			//Definir tamanio con libreria
			//getcwd(path_actual, 74);
			//printf("%s\n", path_actual);
			if (chdir(argv[1])==0)
			{
				printf("%s\n", "Direccion actual");
				system("pwd");
				return true;

			}
			else
			{
				printf("%s\n", "Direccion no valida");
				return false;
			}
			/*if(*(argv[1])=='/')
			{
				if(verificador_abs(argv[1]))
				{	
					chdir(argv[1]);
					//printf("%s\n","Cambio por direccion absoluta" );
					printf("%s%s\n", "Nueva direccion: ",argv[1]);
				}
				else
				{
					printf("%s\n", "Direccion absoluta No valida" );

				}
			}
			else
			{
				if(*(argv[1])=='.')
					char path_relativa[50];
					if(*(argv[1]+1)=='.')
					{
						printf("%s\n","Entro por  2 puntos" );
						sscanf(argv[1],"%s",path_actual);
						printf("%49s\n", );
					}
					else
					{
						printf("%s\n", "Entro por 1 punto");

					}

			

			}  */
		}
			
			





	}
/*
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

	}*/
}

