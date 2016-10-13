#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool verificador(char * path)
{
	if( access( path, F_OK ) != -1 )
	{
		return true;
	} 
	else 
	{
		return false;		
    }
}


bool analizador(char * comando)
{
	if(*(comando)!='/')
	{

		printf("%s\n","No se definio para direcciones no absolutas todavia" );
		return false;
	}
	else
	{
		printf("%s\n","Direccion absoluta " );
		if(verificador(comando))
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

