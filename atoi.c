#include "shell.h"

/**
 * interactive - shell is interactive mode
 * @info: struct information
 *
 * Return: 1 , 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the chararcter
 * @delim: the delimeter
 * Return: 1, 0
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
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
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
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
*/

int _atoi(char *s)
{
	int x, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (x = 0;  s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
		{
			sign *= -1;
		}
		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (s[x] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}
	if (sign == -1)
	{
		output = -res;
	}
	else
	{
		output = res;
	}
	return (output);
}
