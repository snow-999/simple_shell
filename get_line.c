#include "shell.h"
/**
 * inputBuf - buffer command
 * @info: struct information
 * @buff: buffer
 * @leng: leng var
 * Return: x
 *
*/
ssize_t inputBuf(info_t *info, char **buff, size_t *leng)
{
	ssize_t x = 0;
	size_t leng_x = 0;

	if (!*leng)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		x = getline(buff, &leng_x, stdin);
#else
		x = getLine(info, buff, &leng_x);
#endif
		if (x > 0)
		{
			if ((*buff)[x - 1] == '\n')
			{
				(*buff)[x - 1] = '\0';
				x--;
			}
			info->linecount_flag = 1;
			rem_comments(*buff);
			bulid_hist_list(info, *buff, info->histcount++);
			{
				*leng = x;
				info->cmd_buf = buff;
			}
		}
	}
	return (x);
}
/**
 * getInput - get line
 * @info: struct ifromation
 * Return: c
 *
*/
ssize_t getInput(info_t *info)
{
	static char *buff;
	static size_t x, z, leng;
	ssize_t c = 0;
	char **buff_x = &(info->arg), *s;

	_putchar(BUF_FLUSH);
	c = inputBuf(info, &buff, &leng);
	if (c == -1)
	{
		return (-1);
	}
	if (leng)
	{
		z = x;
		s = buff + x;
		checkChain(info, buff, &z, x, leng);
		while (z < leng)
		{
			if (isChain(info, buff, &z))
			{
				break;
			}
			z++;
		}
		x = z + 1;
		if (x >= leng)
		{
			x = leng = 0;
			info->cmd_buf_type = CMD_NOR;
		}
		*buff_x = s;
		return (strglen(s));
	}
	*buff_x = buff;
	return (c);
}
/**
 * readBuf - read buffer
 * @info: struct information
 * @buff: buffer
 * @x: size
 * Return: r
 *
*/
ssize_t readBuf(info_t *info, char *buff, size_t *x)
{
	ssize_t c = 0;

	if (*x)
	{
		return (0);
	}
	c = read(info->readfd, buff, READ_BUF);
	if (c >= 0)
	{
		*x = c;
	}
	return (c);
}
/**
 * getLine - get the next line
 * @info: struct information
 * @str: string
 * @leng: size of ptr buffer
 * Return: s
 *
*/
int getLine(info_t *info, char **str, size_t *leng)
{
	static char buff[READ_BUF];
	static size_t x, lng_x;
	size_t key;
	ssize_t c = 0, s = 0;
	char *ptr = NULL, *n_ptr = NULL, *b;

	ptr = *str;
	if (ptr && leng)
	{
		s = *leng;
	}
	if (x == lng_x)
	{
		x = lng_x = 0;
	}
	c = readBuf(info, buff, &lng_x);
	if (c == -1 || (c == 0 && lng_x == 0))
	{
		return (-1);
	}
	b = strngchr(buff + x, '\n');
	key = b ? 1 + (unsigned int)(b - buff) : lng_x;
	n_ptr = _realloc(ptr, s, s ? s + key : key + 1);
	if (!n_ptr)
	{
		return (ptr ? free(ptr), -1 : -1);
	}
	if (s)
	{
		strngcat(n_ptr, buff + x, key - 1);
	}
	else
	{
		strngcpy(n_ptr, buff + x, key - x + 1);
	}
	s = s + key - x;
	x = key;
	ptr = n_ptr;
	if (leng)
	{
		*leng = s;
	}
	*str = ptr;
	return (s);
}
/**
 * sigintHandler - block control c
 * @sig_num: signal number
 *
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
	_put("\n");
	_put("$ ");
	_putchar(BUF_FLUSH);
}
