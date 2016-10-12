#include <stdio.h>
#include <stdlib.h>

void funcion(int arg,char cmd[],char arg1[], char arg2[])
{
	switch(arg)
	{
		case 1:
			system(cmd);
			break;
		case 2:
			printf("En proceso");
			break;
		default:
			printf("En proceso");
	}
	return;

}