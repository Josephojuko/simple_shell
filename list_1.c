#include "shell.h"

/**
* _listlen - determines list
* @n: pointer node
* Return: sizelist
*/
size_t _listlen(const list_t *n)
{
	size_t w = 0;

	while (n)
	{
		n = n->next;
		n++;
	}
	return (w);
}

/**
* list_to_strings - returns a st->str
* @hed: pointer node
* Return: array
*/
char **list_to_strings(list_t *hed)
{
	list_t *nod = hed;
	size_t w = _listlen(hed), x;
	char **strs;
	char *str;

	if (!hed || !w)
		return (NULL);
	strs = malloc(sizeof(char *) * (w + 1));
	if (!strs)
		return (NULL);
	for (w = 0; nod; nod = nod->next, w++)
	{
		str = malloc(str_len(nod->str) + 1);
		if (!str)
		{
			for (x = 0; x < w; x++)
				free(strs[x]);
			free(strs);
			return (NULL);
		}

		str = str_cpy(str, nod->str);
		strs[w] = str;
	}
	strs[w] = NULL;
	return (strs);
}


/**
* print_list - prints all elist
* @n: pointeto fire
* Return: size of list
*/
size_t print_list(const list_t *n)
{
	size_t w = 0;

	while (n)
	{
		putter(conv_numb(n->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		putter(n->str ? n->str : "(nniill)");
		putter("\n");
		n = n->next;
		w++;
	}
	return (w);
}

/**
* node_startswith - returnwhosex
* @nod: pointead
* @pref: string to
* @k: the next character a
* Return: match node or null
*/
list_t *node_startswith(list_t *nod, char *pref, char k)
{
	char *b = NULL;

	while (nod)
	{
		b = starts_with(nod->str, pref);
		if (b && ((k == -1) || (*b == k)))
			return (nod);
		nod = nod->next;
	}
	return (NULL);
}

/**
* get_node - gets node
* @hed: pointead
* @nod: pointer t
* Return: ode or -1
*/
ssize_t get_node(list_t *hed, list_t *nod)
{
	size_t w = 0;

	while (hed)
	{
		if (hed == nod)
			return (w);
		hed = hed->next;
		w++;
	}
	return (-1);
}
