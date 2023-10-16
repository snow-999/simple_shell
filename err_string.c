#include "shell.h"
/**
 * _eputs - print a string
 * @str: string
*/
void _eputs(char *str)
{
	int x = 0;

	if (!str)
	{
		return;
	}
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}
/**
 * _eputchar - write a character
 * @c: character
 * Return: 1
*/
int _eputchar(char c)
{
	static int x;
	static char buf[WRITE_BUF];

	if (c == BUF_FLUSH || x >= WRITE_BUF)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[x++] = c;
	}
	return (1);
}
/**
 * _putfd - write a character
 * @c: character
 * @fd: file
 * Return: 1
*/
int _putfd(char c, int fd)
{
	static int x;
	static char buf[WRITE_BUF];

	if (c == BUF_FLUSH || x >= WRITE_BUF)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[x++] = c;
	}
	return (1);
}
/**
 * _putsfd - print a string
 * @str: string
 * @fd: file
 * Return: x
*/
int _putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		x = x + _putfd(*str++, fd);
	}
	return (x);
}
