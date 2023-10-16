#include "shell.h"
/**
 * mmemset - fill the memory
 * @s: pointer
 * @b: bytes
 * @n: number of bytes
 * Return: s
*/
char *mmemset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
	s[i] = b;
	}
	return (s);
}
/**
 * ffree - free a string
 * @p: sreting
 *
*/
void ffree(char **p)
{
	char **a = p;

	if (!p)
	{
	return;
	}
	while (*p)
	{
	free(*p++);
	}
	free(a);
}
/**
 * _realloc - realloc a location in momery
 * @ptr: string
 * @o_size: old size of string
 * @n_size: new size of string
 * Return: p
*/
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	char *p;

	if (!ptr)
	{
	return (malloc(n_size));
	}
	if (!n_size)
	{
	free(ptr);
	return (NULL);
	}
	if (n_size == o_size)
	{
	return (ptr);
	}
	p = malloc(n_size);
	if (!p)
	{
	return (NULL);
	}
	if (o_size < n_size)
	{
	o_size = o_size;
	}
	else
	{
	o_size = n_size;
	}
	while (o_size--)
	{
	p[o_size] = ((char *)ptr)[o_size];
	}
	free(ptr);
	return (p);
}
