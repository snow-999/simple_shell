#include "shell.h"
/**
 * list_length - get the length of the list
 * @h: pointer of the head
 * Return: x
*/
size_t list_length(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		h = h->next;
		x++;
	}
	return (x);
}
/**
 * list_to_str - make lists to string
 * @head: pointer of the head node
 * Return: strs
 *
*/
char **list_to_str(list_t *head)
{
	list_t *node = head;
	size_t x = list_length(head), z;
	char **strs;
	char *str;

	if (!head || !x)
	{
	return (NULL);
	}
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
	{
		return (NULL);
	}
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(strglen(node->str) + 1);
		if (!str)
		{
			for (z = 0; z < x; z++)
			{
				free(strs[z]);
			}
			free(strs);
			return (NULL);
		}
		str = strgcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}
/**
 * print_list - print the list
 * @h: pointer of the head node
 * Return: x
*/
size_t print_list(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		_put(convert_num(h->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		_put(h->str ? h->str : "(nil)");
		_put("\n");
		h = h->next;
		x++;
	}
	return (x);
}
/**
 * node_start_w - start with a node
 * @node: node
 * @c: character
 * @prefix: string
 * Return: null
*/
list_t *node_start_w(list_t *node, char *prefix, char c)
{
	char *ptr = NULL;

	while (node)
	{
		ptr = start_w(node->str, prefix);
		if (ptr && ((c == -1) || (*ptr == c)))
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_ind - get the node To index
 * @head: pointer to the head node
 * @node: node
 * Return: -1
*/
ssize_t get_node_ind(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
		{
			return (x);
		}
		head = head->next;
		x++;
	}
	return (-1);
}
