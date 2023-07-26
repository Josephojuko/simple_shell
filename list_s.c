#include "shell.h"

/**
* _addnode - adds alist
* @hed: address of node
* @str: strode
* @numb: node story
* Return: size of
*/
list_t *_addnode(list_t **hed, const char *str, int numb)
{
	list_t *new_hed;

	if (!hed)
		return (NULL);
	new_hed = malloc(sizeof(list_t));
	if (!new_hed)
		return (NULL);
	_memset((void *)new_hed, 0, sizeof(list_t));
	new_hed->num = numb;
	if (str)
	{
		new_hed->str = str_dup(str);
		if (!new_hed->str)
		{
			free(new_hed);
			return (NULL);
		}
	}
	new_hed->next = *hed;
	*hed = new_hed;
	return (new_hed);
}

/**
* add_node_ended - adds a list
* @hed: aress of pnode
* @str: stode
* @numb: nod
* Return: size of
*/
list_t *add_node_ended(list_t **hed, const char *str, int numb)
{
	list_t *new_nod, *nod;

	if (!hed)
		return (NULL);

	nod = *hed;
	new_nod = malloc(sizeof(list_t));
	if (!new_nod)
		return (NULL);
	_memset((void *)new_nod, 0, sizeof(list_t));
	new_nod->num = numb;
	if (str)
	{
		new_nod->str = str_dup(str);
		if (!new_nod->str)
		{
			free(new_nod);
			return (NULL);
		}
	}
	if (nod)
	{
		while (nod->next)
			nod = nod->next;
		nod->next = new_nod;
	}
	else
		*hed = new_nod;
	return (new_nod);
}

/**
* print_list_str - prints list
* @n: pointer node
* Return: size of
*/
size_t print_list_str(const list_t *n)
{
	size_t w = 0;

	while (n)
	{
		putter(n->str ? n->str : "(nniill)");
		putter("\n");
		n = n->next;
		w++;
	}
	return (w);
}

/**
* delete_index - deletes noindex
* @hed: address of node
* @ind: ind of node
* Return: 1 on sss, 0 on
*/
int delete_index(list_t **hed, unsigned int ind)
{
	list_t *nod, *prev_nod;
	unsigned int w = 0;

	if (!hed || !*hed)
		return (0);

	if (!ind)
	{
		nod = *hed;
		*hed = (*hed)->next;
		free(nod->str);
		free(nod);
		return (1);
	}
	nod = *hed;
	while (nod)
	{
		if (w == ind)
		{
			prev_nod->next = nod->next;
			free(nod->str);
			free(nod);
			return (1);
		}
		w++;
		prev_nod = nod;
		nod = nod->next;
	}
	return (0);
}

/**
* fr_list - frees all list
* @hed_ptr: address of node
* Return: void
*/
void fr_list(list_t **hed_ptr)
{
	list_t *nod, *next_nod, *hed;

	if (!hed_ptr || !*hed_ptr)
		return;
	hed = *hed_ptr;
	nod = hed;
	while (nod)
	{
		next_nod = nod->next;
		free(nod->str);
		free(nod);
		nod = next_nod;
	}
	*hed_ptr = NULL;
}

