#include "shell.h"
/**
 * isCmd - find command
 * @info: struct infromation
 * @path: the file path
 * Return: 0
 *
*/
int isCmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
	{
		return (0);
	}
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * dupChars - duplecate characters
 * @pathptr: path string
 * @strt: start
 * @stp: stop
 * Return: bff
 *
*/
char *dupChars(char *pathptr, int strt, int stp)
{
	static char bff[1024];
	int x = 0, z = 0;

	for (z = 0, x = strt; x < stp; x++)
	{
		if (pathptr[x] != ':')
		{
			bff[z++] = pathptr[x];
		}
	}
	bff[z] = 0;
	return (bff);
}
/**
 * findPath - find path string
 * @info: struct infromation
 * @pathptr: path string
 * @cmd: command
 * Return: path
 *
*/
char *findPath(info_t *info, char *pathptr, char *cmd)
{
	int x = 0, crr_ps = 0;
	char *path;

	if (!pathptr)
	{
		return (NULL);
	}
	if ((strglen(cmd) > 2) && start_w(cmd, "./"))
	{
		if (isCmd(info, cmd))
		{
			return (cmd);
		}
	}
	while (1)
	{
		if (!pathptr[x] || pathptr[x] == ':')
		{
			path = dupChars(pathptr, crr_ps, x);
			if (!*path)
			{
				strgcat(path, cmd);
			}
			else
			{
				strgcat(path, "/");
				strgcat(path, cmd);
			}
			if (isCmd(info, path))
			{
				return (path);
			}
			if (!pathptr[x])
			{
				break;
			}
			crr_ps = x;
		}
		x++;
	}
	return (NULL);
}
