#include "shell.h"
/**
 * hsh - main loop
 * @info: struct infromation
 * @av: argument
 * Return: 0
 *
*/
int hsh(info_t *info, char **av)
{
	ssize_t x = 0;
	int bulitIn_r = 0;

	while (x != -1 && bulitIn_r != -2)
	{
		clear_inf(info);
		if (interactive(info))
		{
			_put("$ ");
			_eputchar(BUF_FLUSH);
			x = getInput(info);
			if (x != -1)
			{
				set_inf(info, av);
				bulitIn_r = findBulitin(info);
				if (bulitIn_r == -1)
				{
					findCmd(info);
				}
			}
			else if (interactive(info))
			{
				_putchar('\n');
			}
			free_inf(info, 0);
		}
	}
	write_his(info);
	free_inf(info, 1);
	if (!interactive(info) && info->status)
	{
		exit(info->status);
	}
	if (bulitIn_r == -2)
	{
		if (info->err_num == -1)
		{
			exit(info->status);
		}
		exit(info->err_num);
	}
	return (bulitIn_r);
}
/**
 * findBulitin - find built in commands
 * @info: struct infromatiom
 * Return: -1
 *
*/
int findBulitin(info_t *info)
{
	int x, bulitin_r = -1;
	bulitin_table bulitintbl[] = {
		{"exit", myExit},
		{"env", myEnv},
		{"help", myHelp},
		{"history", myHistory},
		{"setenv", mySetEnv},
		{"unsetenv", myuSetEnv},
		{"cd", MyCd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (x = 0; bulitintbl[x].type; x++)
	{
		if (strgcmp(info->argv[0], bulitintbl[x].type) == 0)
		{
			info->line_count++;
			bulitin_r = bulitintbl[x].func(info);
			break;
		}
	}
	return (bulitin_r);
}
/**
 * findCmd - find command path
 * @info: struct information
 *
*/
void findCmd(info_t *info)
{
	char *path = NULL;
	int x, c;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (x = 0, c = 0; info->arg[x]; x++)
	{
		if (!is_delim(info->arg[x], "\t\n"))
		{
			c++;
		}
	}
	if (!c)
	{
		return;
	}
	path = findPath(info, getEnv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		forkCmd(info);
	}
	else
	{
		if ((interactive(info) || getEnv(info, "PATH=")
			|| info->argv[0][0] == '/') && isCmd(info, info->argv[0]))
		{
			forkCmd(info);
		}
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "notfound\n");
		}
	}
}
/**
 * forkCmd - fork to run command
 * @info: struct infromation
 *
*/
void forkCmd(info_t *info)
{
	pid_t child_pd;

	child_pd = fork();
	if (child_pd == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pd == 0)
	{
		if (execve(info->path, info->argv, get_env(info)) == -1)
		{
			free_inf(info, 1);
			if (errno == EACCES)
			{
				exit(126);
			}
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
			{
				print_error(info, "permision denaied\n");
			}
		}
	}
}
