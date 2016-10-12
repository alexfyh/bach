#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funcion(int arg,char cmd[],char arg1[], char arg2[])
{
	char llamada [50];
	switch(arg)
	{
		case 1:
			system(cmd);
			break;
		case 2:
			strcpy(llamada,cmd);
			strcat(llamada," ");
			strcat(llamada,arg1);
			system(llamada);
			//printf("%s\n",llamada);
			break;
		case 3:
			strcpy(llamada,cmd);
			strcat(llamada," ");
			strcat(llamada,arg1);
			strcat(llamada," ");
			strcat(llamada,arg2);
			printf("%s\n", llamada);
			break;
		default:
			printf("%s\n","Ingrese un comando");
	}
	return;

}