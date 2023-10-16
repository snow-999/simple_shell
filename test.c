#include "shell.h"
/**
 * isChain - test if chain works
 * @info: struct infromation
 * @buff: buffer
 * @s: string
 * Return: 0
 *
*/
int isChain(info_t *info, char *buff, size_t *s)
{
	size_t x = *s;

	if (buff[x] == '|' && buff[x + 1] == '|')
	{
		buff[x] = 0;
		x++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buff[x] == '&' && buff[x + 1] == '&')
	{
		buff[x] = 0;
		x++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buff[x] == ';')
	{
		buff[x] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
	{
		return (0);
	}
	*s = x;
	return (1);
}
/**
 * checkChain - check chaining
 * @info: struct iromation
 * @buff: buffer
 * @s: string
 * @x: start
 * @leng: length
 *
 *
*/
void checkChain(info_t *info, char *buff, size_t *s, size_t x, size_t leng)
{
	size_t z = *s;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buff[x] = 0;
			z = leng;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
		buff[x] = 0;
		z = leng;
		}
	}
	*s = z;
}
/**
 * replace_alias - replace alias in string
 * @info: struct ifromation
 * Return: 0
 *
*/
int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *s;

	for (x = 0; x < 10; x++)
	{
		node = node_start_w(info->alias, info->argv[0], '=');
		if (!node)
		{
			return (0);
		}
		free(info->argv[0]);
		s = strngchr(node->str, '=');
		if (!s)
		{
			return (0);
		}
		s = strdup(s + 1);
		if (!s)
		{
			return (0);
		}
		info->argv[0] = s;
	}
	return (1);
}
/**
 * replace_vars - replace vars in string
 * @info: struct infromation
 * Return: 0
 *
*/
int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
		{
			continue;
		}
		if (!strgcmp(info->argv[x], "$?"))
		{
			replace_str(&(info->argv[x]),
				strgdup(convert_num(info->status, 10, 0)));
			continue;
		}
		if (!strgcmp(info->argv[x], "$$"))
		{
			replace_str(&(info->argv[x]),
					strgdup(convert_num(getpid(), 10, 0)));
			continue;
		}
		node = node_start_w(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_str(&(info->argv[x]),
					strgdup(strngchr(node->str, '=') + 1));
			continue;
		}
		replace_str(&info->argv[x], strgdup(""));
	}
	return (0);
}
/**
 * replace_str - replace string
 * @old: old string
 * @new: new string
 * Return: 1
 *
*/
int replace_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
