#include "shell.h"

/**
 *_memset - fills memory
 *@s: pointer
 *@b: bytes
 *@n: number
 *Return: str
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * ffree - free string
 * @pp: string
 */
void ffree(char **pp)
{
	char **ar = pp;

	if (!pp)
	{
		return;
	}
	while (*pp)
	{
		free(*pp++);
	}
	free(ar);
}

/**
 * _realloc - reallocates new memory
 * @ptr: pointer
 * @old_size: old size
 * @new_size: new size
 *
 * Return: str
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *str;

	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (!new_size)
	{
		return (free(ptr), NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	str = malloc(new_size);
	if (!str)
	{
		return (NULL);
	}
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	{
		str[old_size] = ((char *)ptr)[old_size];
	}
	free(ptr);
	return (str);
}
