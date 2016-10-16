#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cadena_path ()
{
	char * pPath = getenv ("PATH");
	return pPath;
}
