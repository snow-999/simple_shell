#include "shell.h"
/**
 * _erratoi - string to integer
 * @str: string
 * Return: res
*/
int _erratoi(char *str)
{
	int i = 0;
	unsigned long int res = 0;

	if (*str == '+')
	{
	str++;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10;
			res = res + (str[i] - '0');
			if (res > INT_MAX)
			{
				return (-1);
			}
		}
		else
		{
		return (-1);
		}
	}
	return (res);
}
/**
 * print_error - print an error
 * @info: information
 * @erstr: string
 *
*/
void print_error(info_t *info, char *erstr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(erstr);
}
/**
 * print_d - print integer
 * @input: intput
 * @fd: the file will be opened
 * Return: c
*/
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, c = 0;
	unsigned int _abs_, curr;

	if (fd == STDERR_FILENO)
	{
		__putchar = _eputchar;
	}
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		c++;
	}
	else
	{
	_abs_ = input;
	}
	curr = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + curr / i);
			c++;
		}
		curr %= i;
	}
	__putchar('0' + curr);
	c++;
	return (c);
}
/**
 * convert_num - convert numbers
 * @num: number
 * @base: base
 * @flag: flag
 * Return: ptr
*/
char *convert_num(long int num, int base, int flag)
{
	static char *arr;
	static char buff[50];
	char s = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
	n = -num;
	s = '-';
	}
	arr = flag & CONVERT_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';
	do {
	*--ptr = arr[n % base];
	n /= base;
	} while (n != 0);
	if (s)
	{
	*--ptr = s;
	}
	return (ptr);
}
/**
 * rem_comments - remove comments
 * @buf: buffer
 *
*/
void rem_comments(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
	{
		if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;
		}
	}
}
