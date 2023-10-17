#include "shell.h"
/**
 * strow - split string
 * @str: string
 * @d: delimeter
 * Return: s
*/
char **strwo(char *str, char *d)
{
	int i, x, z, l, nwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	if (!d)
	{
		d = " ";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
		{
			nwords++;
		}
	}
	if (nwords == 0)
	{
		return (NULL);
	}
	s = malloc((1 + nwords) * sizeof(char *));
	if (!s)
	{
		return (NULL);
	}
	for (i = 0, x = 0; x < nwords; x++)
	{
		while (is_delim(str[i], d))
		{
			i++;
		}
		z = 0;
		while (!is_delim(str[i + z], d) && str[i + z])
		{
			z++;
		}
		s[x] = malloc((z + 1) * sizeof(char));
		if (!s[x])
		{
			for (z = 0; z < x; z++)
			{
				free(s[z]);
			}
			free(s);
			return (NULL);
		}
		for (l = 0; l < z; l++)
		{
			s[z][l] = str[i++];
		}
		s[z][l] = 0;
	}
	s[z] = NULL;
	return (s);
}
/**
 * strow2 - split string
 * @str: string
 * @d: delimeter
 * Return: s
 *
*/
char **strow2(char *str, char d)
{
	int i, z, x, l, nwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] != d && str[i + 1] == d) ||
			(str[i] != d && !str[i + 1]) || str[i + 1] == d)
		{
			nwords++;
		}
	}
	if (nwords == 0)
	{
		return (NULL);
	}
	s = malloc((1 + nwords) * sizeof(char *));
	if (!s)
	{
		return (NULL);
	}
	for (i = 0, z = 0; z < nwords; z++)
	{
		while (str[i] == d && str[i] != d)
		{
			i++;
		}
		x = 0;
		while (str[i + x] != d && str[i + x] && str[i + x] != d)
		{
			x++;
		}
		s[z] = malloc((x + 1) * sizeof(char));
		if (!s[z])
		{
			for (x = 0; x < z; x++)
			{
				free(s[x]);
			}
			free(s);
			return (NULL);
		}
		for (l = 0; l < x; l++)
		{
			s[z][l] = str[i++];
		}
		s[z][l] = 0;
	}
	s[z] = NULL;
	return (s);
}
