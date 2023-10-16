#include "shell.h"
/**
 * myExit - exit the shell
 * @info: the struct infromation
 * Return: exit
 *
*/
int myExit(info_t *info)
{
	int exitchck;

	if (info->argv[1])
	{
		exitchck = _erratoi(info->argv[1]);
		if (exitchck == -1)
		{
			info->status = 2;
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * MyCd - change my directory
 * @info: the struct information
 * Return: 0
 *
*/
int MyCd(info_t *info)
{
	char *str, *dir, buff[1024];
	int chdir_r;

	str = getcwd(buff, 1024);
	if (!str)
	{
		_put("TODO : >>getcwd failure emsg here<<\n");
	}
	if (!info->argv[1])
	{
		dir = getEnv(info, "HOME=");
		if (!dir)
		{
			chdir_r = chdir((dir = getEnv(info, "PWD=")) ? dir : "/");
		}
		else
		{
			chdir_r = chdir(dir);
		}
	}
	else if (strgcmp(info->argv[1], "-") == 0)
	{
		if (!getEnv(info, "OLDPWD="))
		{
			_put(str);
			_putchar('\n');
			return (1);
		}
		_put(getEnv(info, "OLDPWD=")), _putchar('\n');
		chdir_r = chdir((dir = getEnv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	{
		chdir_r = chdir(info->argv[1]);
	}
	if (chdir_r == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWF", getEnv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buff, 1024));
	}
	return (0);
}
/**
 * myHelp - change directory
 * @info: struct infromation
 * Return: 0
 *
*/
int myHelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_put("help call works. function not yet implemented \n");
	if (0)
	{
		_put(*arg_arr);
	}
	return (0);
}
