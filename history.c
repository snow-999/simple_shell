#include "shell.h"
/**
 * get_history_f - get history file
 * @info: struct infromation
 * Return: buff
 *
*/
char *get_history_f(info_t *info)
{
	char *buff, *dir;

	dir = getEnv(info, "HOME=");
	if (!dir)
	{
		return (NULL);
	}
	buff = malloc(sizeof(char) * (strglen(dir) + strglen(HIST_FILE) + 2));
	if (!buff)
	{
		return (NULL);
	}
	buff[0] = 0;
	strgcpy(buff, dir);
	strgcat(buff, "/");
	strgcat(buff, HIST_FILE);
	return (buff);
}
/**
 * write_his - creat a file
 * @info: strict information
 * Return: 1
*/
int write_his(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_f(info);
	list_t *node;

	if (!filename)
	{
		return (-1);
	}
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
	{
		return (-1);
	}
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
/**
 * read_his - read history from file
 * @info: struct info
 * Return: history
 *
*/
int read_his(info_t *info)
{
	int x, lt = 0, linc = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buff = NULL, *filename = get_history_f(info);

	if (!filename)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
	{
		return (0);
	}
	if (!fstat(fd, &st))
	{
		fsize = st.st_size;
	}
	if (fsize < 2)
	{
		return (0);
	}
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
	{
		return (0);
	}
	rdlen = read(fd, buff, fsize);
	buff[fsize] = 0;
	if (rdlen <= 0)
	{
		return (free(buff), 0);
	}
	close(fd);
	for (x = 0; x < fsize; x++)
	{
		if (buff[x] == '\n')
		{
			buff[x] = 0;
			bulid_hist_list(info, buff + lt, linc++);
			lt = x + 1;
		}
	}
	if (lt != x)
	{
		bulid_hist_list(info, buff + lt, linc++);
	}
	free(buff);
	info->histcount = linc;
	while (info->histcount-- >= HIST_MAX)
	{
		delet_node(&(info->history), 0);
	}
	renumber_hist(info);
	return (info->histcount);
}
/**
 * bulid_hist_list - add history
 * @info: struct infromation
 * @linc: history line count
 * @buff: buffer
 * Return: 0
*/
int bulid_hist_list(info_t *info, char *buff, int linc)
{
	list_t *node = NULL;

	if (info->history)
	{
		node = info->history;
	}
	add_node_end(&node, buff, linc);
	if (!info->history)
	{
		info->history = node;
	}
	return (0);
}
/**
 * renumber_hist - renumber history list
 * @info: struct infromation
 * Return: histcount
 *
*/
int renumber_hist(info_t *info)
{
	list_t *node = info->history;
	int x = 0;

	while (node)
	{
		node->n = x++;
		node = node->next;
	}
	return (info->histcount = x);
}
