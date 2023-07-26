#include "shell.h"

/**
* bfree - frees a ress
* @ptr: addrfree
* Return: 1 if, othse 0.
*/
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

