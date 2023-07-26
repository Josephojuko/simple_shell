#include "shell.h"

/**
* his_tory - displays the histoby
* @io: Structure containiarguments
* Return: Always 0
*/
int his_tory(io_t *io)
{
	print_list(io->history);
	return (0);
}

/**
* unset_ali_as - setsstring
* @io: parastruct
* @str: the string alias
* Return: Always 0 on success, 1 on error
*/
int unset_ali_as(io_t *io, char *str)
{
	char *b, k;
	int rat;

	b = str_chr(str, '=');
	if (!b)
		return (1);
	k = *b;
	*b = 0;
	rat = delete_index(&(io->alias),
		get_node(io->alias, node_startswith(io->alias, str, -1)));
	*b = k;
	return (rat);
}

/**
* set_ali_as - sstring
* @io: parameuct
* @str: thealias
* Return: Always 0 on success, 1 on failure
*/
int set_ali_as(io_t *io, char *str)
{
	char *b;

	b = str_chr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_ali_as(io, str));

	unset_ali_as(io, str);
	return (add_node_ended(&(io->alias), str, 0) == NULL);
}

/**
* print_ali_as - prints ring
* @nod: the node
* Return: Always 0 on success, 1 on failure
*/
int print_ali_as(list_t *nod)
{
	char *b = NULL, *a = NULL;

	if (nod)
	{
		b = str_chr(nod->str, '=');
		for (a = nod->str; a <= b; a++)
			_putchar(*a);
		_putchar('\'');
		putter(b + 1);
		putter("'\n");
		return (0);
	}
	return (1);
}

/**
* my_alias - mimicsbuiltin
* @io: Structure coarguments
* Return: Always 0
*/
int my_alias(io_t *io)
{
	int i = 0;
	char *b = NULL;
	list_t *nod = NULL;

	if (io->argc == 1)
	{
		nod = io->alias;
		while (nod)
		{
			print_ali_as(nod);
			nod = nod->next;
		}
		return (0);
	}
	for (i = 1; io->argv[i]; i++)
	{
		b = str_chr(io->argv[i], '=');
		if (b)
			set_ali_as(io, io->argv[i]);
		else
			print_ali_as(node_startswith(io->alias, io->argv[i], '='));
	}

	return (0);
}
