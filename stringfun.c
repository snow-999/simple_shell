#include "shell.h"
/**
 * strglen - get string length
 * @c: string
 * Return: i the number of index
*/
int strglen(char *c)
{
	int i = 0;

	if (!c)
	{
	return (0);
	}
	while (*c++)
	{
	i++;
	}
	return (i);
}
/**
 * strgcmp - comper the string
 * @c1: first sstring
 * @c2: sacond string
 * Return: 0,1,-1
*/
int strgcmp(char *c1, char *c2)
{
	while (*c1 && *c2)
	{
		if (*c1 != *c2)
		{
		return (*c1 - *c2);
		}
		c1++;
		c2++;
	}
	if (*c1 == *c2)
	{
	return (0);
	}
	else if (*c1 < *c2)
	{
	return (-1);
	}
	else
	{
	return (1);
	}
}
/**
 * start_w - starts with function
 * @haystack: string
 * @needle: string we need
 * Return: haystack
*/
char *start_w(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
		{
		return (NULL);
		}
	}
	return ((char *)haystack);
}
/**
 * strgcat - cuntine the string
 * @dest: string
 * @src: string
 * Return: soc
*/
char *strgcat(char *dest, char *src)
{
	char *soc = dest;

	while (*dest)
	{
	dest++;
	}
	while (*src)
	{
	*dest++ = *src++;
	}
	*dest = *src;
	return (soc);
}
