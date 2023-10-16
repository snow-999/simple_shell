#include "shell.h"
/**
 * myEnv - print the enviroment
 * @info: the struct infromation
 * Return: 0
*/
int myEnv(info_t *info)
{
	print_list_ptr(info->env);
	return (0);
}
/**
 * getEnv - get the enviroment
 * @info: struct information
 * @name: enviroment name
 * Return: NULL
 *
*/
char *getEnv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *s;

	while (node)
	{
		s = start_w(node->str, name);
		if (s && *s)
		{
			return (s);
		}
		node = node->next;
	}
	return (NULL);
}
/**
 * mySetEnv - set the enviroment
 * @info: struct information
 * Return: 1, 0
*/
int mySetEnv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("INcorect number of argument\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
	{
		return (0);
	}
	return (1);
}
/**
 * myuSetEnv - remove the enviroment
 * @info: the struct info
 * Return: 0
 *
*/
int myuSetEnv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("too few arguments.\n");
		return (1);
	}
	for (x = 0; x <= info->argc; x++)
	{
		_unsetenv(info, info->argv[x]);
	}
	return (0);
}
/**
 * populate_env_list - populate environ linked list
 * @info: struct information
 * Return: 0
 *
*/
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
	{
		add_node_end(&node, environ[x], 0);
	}
	info->env = node;
	return (0);
}
