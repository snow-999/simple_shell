#include "shell.h"
/**
 * myHistory - history list
 * @info: struct infromation
 * Return: 0
 *
*/
int myHistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - set alias to string
 * @info: struct informatiom
 * @str: string
 * Return: rt
 *
*/
int unset_alias(info_t *info, char *str)
{
	char *s, ch;
	int rt;

	s = strngchr(str, '=');
	if (!s)
	{
		return (1);
	}
	ch = *s;
	*s = 0;
	rt = delet_node(&(info->alias),
	   get_node_ind(info->alias, node_start_w(info->alias, str, -1)));
	*s = ch;
	return (rt);
}
/**
 * set_alias - set alias to string
 * @info: struct ifromation
 * @str: string
 * Return: 0
 *
*/
int set_alias(info_t *info, char *str)
{
	char *s;

	s = strngchr(str, '=');
	if (!s)
	{
		return (1);
	}
	if (!*++s)
	{
		return (unset_alias(info, str));
	}
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - print alias list
 * @node: node list
 * Return: 0
 *
*/
int print_alias(list_t *node)
{
	char *s = NULL, *arr = NULL;

	if (node)
	{
		s = strngchr(node->str, '=');
		for (arr = node->str; arr <= s; arr++)
		{
			_putchar(*arr);
		}
		_putchar('\'');
		_put(s + 1);
		_put("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - set my alias
 * @info: struct infromation
 * Return: 0
 *
*/
int _myalias(info_t *info)
{
	int x = 0;
	char *s = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		s = strngchr(info->argv[x], '=');
		if (s)
		{
			set_alias(info, info->argv[x]);
		}
		else
		{
			print_alias(node_start_w(info->alias, info->argv[x], '='));
		}
	}
	return (0);
}
