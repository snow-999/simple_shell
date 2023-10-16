#include "shell.h"

/**
 * strgcpy - copy string
 * @src: string
 * @dest: string
 * Return: dest
*/
char *strgcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
	{
	return (dest);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
 * strgdup - duplicate the string
 * @ptr: string
 * Return: pointer
*/
char *strgdup(const char *ptr)
{
	int len = 0;
	char *soc;

	if (ptr == NULL)
	{
	return (NULL);
	}
	while (*ptr++)
	{
	len++;
	}
	soc = malloc(sizeof(char) * (len + 1));
	if (!soc)
	{
	return (NULL);
	}
	for (len++; len--;)
	{
	soc[len] = *--ptr;
	}
	return (soc);
}
/**
 * _put - print a string
 * @ptr: string
 *
*/
void _put(char *ptr)
{
	int i = 0;

	while (ptr[i] != '\0')
	{
	_putchar(ptr[i]);
	i++;
	}
}
/**
 * _putchar - print character
 * @c: character of string
 * Return: 1
*/
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF];

	if (c == BUF_FLUSH || i >= WRITE_BUF)
	{
	write(1, buf, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	{
	buf[i++] = c;
	}
	return (1);
}
