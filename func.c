#include "shell.h"
/**
 * interactive - function for inter active mode
 * @info: infromation
 * Return: 1
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - check delimeters
 * @c: character
 * @delim: delimeter
 * Return: 1
 *
*/
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
		{
		return (1);
		}
	}
	return (1);
}
/**
 * _isalpha - check the aslphapet
 * @c: character
 * Return: 0, 1
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
	return (0);
	}
}
/**
 * _atoi - string to integer
 * @str: string
 * Return: out
*/
int _atoi(char *str)
{
	int i, s = 1, f = 0, out;
	unsigned int res = 0;

	for (i = 0; str[i] != '\0' && f != 2; i++)
	{
		if (str[i] == '-')
		{
		s = s * -1;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
		f = 1;
		res = res * 10;
		res = res + (str[i] - '0');
		}
		else if (f == 1)
		{
		f = 2;
		}
	}
	if (s == -1)
	{
	out = -res;
	}
	else
	{
	out = res;
	}
	return (out);
}
