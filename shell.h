#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF 1024
#define WRITE_BUF 1024
#define BUF_FLUSH -1

#define CMD_NOR 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWER 1
#define CONVERT_UNSIGNED 2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE  ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct lists - singl list
 * @n: number
 * @str: string
 * @next: pointer to next node
 *
*/
typedef struct lists
{
	int n;
	char *str;
	struct lists *next;
} list_t;

/**
 * struct information - information we need
 * @arg: string
 * @argv: array of string
 * @path: a string of path
 * @argc: number of arguments
 * @line_count: err count
 * @linecount_flag: line of input
 * @err_num: error code
 * @fname: program file
 * @env: linked list
 * @environ: custom
 * @history: history node
 * @alias: alias node
 * @env_changed: if anviron was changed
 * @status: status
 * @cmd_buf: pointer to cmd
 * @cmd_buf_type: type of cmd buf
 * @readfd: the fd from reaf line
 * @histcount: history line
 *
*/
typedef struct information
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - bulitin string we need
 * @type: command flag
 * @func: function
 *
*/
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} bulitin_table;

/* strings */
int strglen(char *);
int strgcmp(char *, char *);
char *start_w(const char *, const char *);
char *strgcat(char *, char *);
char *strgcpy(char *, char *);
char *strgdup(const char *);
void _put(char *);
int _putchar(char);
char *strngcpy(char *, char *, int);
char *strngcat(char *, char *, int);
char *strngchr(char *, char);
char **strwo(char *, char *);
char **strwo2(char *, char);
char *mmemset(char *s, char b, unsigned int n);
void ffree(char **p);
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size);
int bfree(void **ptr);
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *str);
int _erratoi(char *str);
void print_error(info_t *info, char *erstr);
int print_d(int input, int fd);
char *convert_num(long int num, int base, int flag);
void rem_comments(char *buf);
list_t *add_node_start(list_t **node, const char *str, int n);
size_t print_list_ptr(const list_t *h);
void free_list(list_t **h_ptr);
list_t *add_node_end(list_t **head, const char *str, int n);
int delet_node(list_t **head, unsigned int ind);
size_t list_length(const list_t *h);
char **list_to_str(list_t *head);
size_t print_list(const list_t *h);
list_t *node_start_w(list_t *node, char *prefix, char c);
ssize_t get_node_ind(list_t *head, list_t *node);
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
void free_inf(info_t *info, int all);
void set_inf(info_t *info, char **av);
void clear_inf(info_t *info);
int myEnv(info_t *info);
char *getEnv(info_t *info, const char *name);
int mySetEnv(info_t *info);
int myuSetEnv(info_t *info);
int populate_env_list(info_t *info);
int _setenv(info_t *info, char *var, char *value);
int _unsetenv(info_t *info, char *var);
char **get_env(info_t *info);
char *get_history_f(info_t *info);
int write_his(info_t *info);
int read_his(info_t *info);
int bulid_hist_list(info_t *info, char *buff, int linc);
int renumber_hist(info_t *info);
int myHelp(info_t *info);
int MyCd(info_t *info);
int myExit(info_t *info);
int myHistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);
int isChain(info_t *info, char *buff, size_t *s);
void checkChain(info_t *info, char *buff, size_t *s, size_t x, size_t leng);
int replace_alias(info_t *info);
int replace_vars(info_t *info);
int replace_str(char **old, char *new);
int isCmd(info_t *info, char *path);
char *dupChars(char *pathptr, int strt, int stp);
char *findPath(info_t *info, char *pathptr, char *cmd);
int hsh(info_t *info, char **av);
int findBulitin(info_t *info);
void findCmd(info_t *info);
void forkCmd(info_t *info);
ssize_t inputBuf(info_t *info, char **buff, size_t *leng);
ssize_t getInput(info_t *info);
ssize_t readBuf(info_t *info, char *buff, size_t *x);
int getLine(info_t *info, char **str, size_t *leng);
void sigintHandler(__attribute__((unused))int sig_num);





#endif /* simple shell */
