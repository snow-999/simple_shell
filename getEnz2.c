#include "shell.h"
/**
 * get_env - get yhe string from environ
 * @info: struct infromation
 * Return: 0
 *
*/
char **get_env(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_str(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}
/**
 * _unsetenv - remove the environ
 * @info: the dtruct information
 * @var: string
 * Return: 0
 *
*/
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t x = 0;
	char *s;

	if (!node || !var)
	{
	return (0);
	}
	while (node)
	{
		s = start_w(node->str, var);
		if (s && *s == '=')
		{
			info->env_changed = delet_node(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (info->env_changed);
}
/**
 * _setenv - set an environ
 * @info: struct infromatoin
 * @var: string
 * @value: string
 * Return: 0
 *
*/
int _setenv(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *s;

	if (!var || !value)
	{
		return (0);
	}
	buff = malloc(strglen(var) + strglen(value) + 2);
	if (!buff)
	{
	return (1);
	}
	strgcpy(buff, var);
	strgcat(buff, "=");
	strgcat(buff, value);
	node = info->env;
	while (node)
	{
		s = start_w(node->str, var);
		if (s && *s == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}

