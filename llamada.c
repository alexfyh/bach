#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	//printf("%s%s\n", argv[0],argv[1]);
	char  * ejecutar[125];
	fgets(ejecutar,124,stdin);
	printf("%s\n", ejecutar);
	return 0;
}