#include "shell.h"

/**
 * bfree - frees a pointer
 * @ptr: ptr
 *
 * Return: 1, 0
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
