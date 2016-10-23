#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int cantidad_cadenas(char* cadena,char separador)
{
	int i=0;
	int c=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]==separador)
			{
				c++;
			}
		i++;
		}
		return c;
	}
	else
	{
		printf("%s\n","Cadena invalida");
		return -1;
		// ver que significa -1
	}
}

void asignador(char * cadena,int size,char * arreglo[], char *separador)
{
	int i=0;
	char * token;
	token = strtok(cadena, separador);
	arreglo[i]=token;
	i++;
	while(i<size)
   {
      	token = strtok(NULL, separador);
      	arreglo[i]=token;
      	i++;
   }
}