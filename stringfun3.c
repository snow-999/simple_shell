#include "shell.h"
/**
 * strngcpy - copy string
 * @dest: string
 * @src: string
 * @x: number of index
 * Retrn: a
*/
char *strngcpy(char *dest, char *src, int x)
{
	int i, z;
	char *a = dest;

	i = 0;
	while (src[i] != '\0' && i < x - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < x)
	{
		z = i;
		while (z < x)
		{
		dest[z] = '\0';
		z++;
		}
	}
	return (a);
}
/**
 * strngcat - concatenate a string
 * @dest: string
 * @src: string
 * @x: number of index
 * Return: a
*/
char *strngcat(char *dest, char *src, int x)
{
	int i = 0;
	int z = 0;
	char *a = dest;

	while (dest[i] != '\0')
	{
	i++;
	}
	while (src[z] != '\0' && z < x)
	{
		dest[z] = src[z];
		i++;
		z++;
	}
	if (z < x)
	{
	dest[i] = '\0';
	}
	return (a);
}
/**
 * strgchr - find a charcter in string
 * @str: string
 * @c: charchter
 * Return: NULL
*/
char *strngchr(char *str, char c)
{
	do {
		if (*str == c)
		{
		return (str);
		}
	} while (*str++ != '\0');
	return (NULL);
}
