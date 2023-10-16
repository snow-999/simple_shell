#include "shell.h"
/**
 * add_node_start - add node at the begining of list
 * @node: node
 * @str: string
 * @n: number of lists
 * Return: new_head
*/
list_t *add_node_start(list_t **head, const char *str, int n)
{
	list_t *new_head;

	if (!head)
	{
		return (NULL);
	}
	new_head = malloc(sizeof(list_t));
	if (!new_head)
	{
		return (NULL);
	}
	mmemset((void *)new_head, 0, sizeof(list_t));
	new_head->n = n;
	if (str)
	{
		new_head->str = strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}
/**
 * print_list - print the content of the list
 * @h: node
 * Return: x
*/
size_t print_list_ptr(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		_put(h->str ? h->str : "(nil)");
		_put("\n");
		h = h->next;
		x++;
	}
	return (x);
}
/**
 * free_list - free the list
 * @h_ptr: pointer of the head
 *
*/
void free_list(list_t **h_ptr)
{
	list_t *node, *head, *next_node;

	if (!h_ptr || !*h_ptr)
	{
		return;
	}
	head = *h_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*h_ptr = NULL;
}
/**
 * add_node_end - add node at the end
 * @head: pointer of the head
 * @str: pointer of string
 * @n: number of index in the list
 * Return: new_n
*/
list_t *add_node_end(list_t **head, const char *str, int n)
{
	list_t *new_n, *node;

	if (!head)
	{
		return (NULL);
	}
	node = *head;
	new_n = malloc(sizeof(list_t));
	if (!new_n)
	{
		return (NULL);
	}
	mmemset((void *)new_n, 0, sizeof(list_t));
	new_n->n = n;
	if (str)
	{
		new_n->str = strdup(str);
		if (!new_n->str)
		{
			free(new_n);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = new_n;
	}
	else
	{
		*head = new_n;
	}
	return (new_n);
}
/**
 * delet_node - delet node
 * @head: pointer of the head
 * @ind: index
 * Return: 1
*/
int delet_node(list_t **head, unsigned int ind)
{
	list_t *node, *perv_n;
	unsigned int x = 0;

	if (!head || !*head)
	{
	return (0);
	}
	if (!ind)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (x == ind)
		{
			perv_n->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		x++;
		perv_n = node;
		node = node->next;
	}
	return (0);
}
