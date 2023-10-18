#include "shell.h"

/**
 * _strlen - get length of a string
 * @s: the string
 *
 * Return: i
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
	{
		return (0);
	}
	while (*s++)
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - comparison of two strangs.
 * @s1: string
 * @s2: string
 *
 * Return: -1, 1
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 < *s2 ? -1 : 1);
	}
}

/**
 * starts_with - starts with haystack
 * @haystack: string
 * @needle: find charcter
 *
 * Return: haystack
*/
char *starts_with(const char *haystack, const char *needle)
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
 * _strcat - concatenates two strings
 * @dest: srting
 * @src: string
 *
 * Return: ret
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
	*dest++ = *src++;
	}
	*dest = *src;
	return (ret);
}
