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

/*
int catidad_comandos(int argc,char * argv[])
{
	int posicion=0;
	if(posicion<argc)
	{
		if(strcmp(argv[i],menor)||strcmp(argv[i],mayor)||strcmp(argv[i],tuberia))
		{

		}


	posicion++;
	}
	
}
*/
/*

int main ()
{
  int i=0;
  int c=0;
  char * pPath;
  char * token;
  pPath = getenv ("PATH");

  if (pPath!=NULL)
    //printf ("The current path is: %s",pPath);
	{while(pPath[i]!='\0')
		{if(pPath[i]==':')
			{
				c++;
			}
		i++;

		}
	}
	else
		{
			printf("%s\n","No se han encontrado direcciones para las variables de entorno");
			//exit(0);

		}
	printf("\n%d\n",c );
	i=0;
	char * direcciones[c+1];
	printf("%s\n",pPath );

	token = strtok(pPath, ":");
	direcciones[i]=token;
	i++;
	
   while(i<c+1)
   //while( token != NULL ) 
   {
      	token = strtok(NULL, ":");
      	direcciones[i]=token;
      	i++;
   }
   i=0;
   while(i<c+1)
   {
   		printf( "%d%s\n",i, direcciones[i] );
   		i++;
   }
  return 0;
}
*/