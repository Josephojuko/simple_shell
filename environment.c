#include "shell.h"

/**
* my_env - prinonment
* @io: Structure arguments
* Return: Always 0
*/
int my_env(io_t *io)
{
	print_list_str(io->env);
	return (0);
}

/**
* get_envr - gets variable
* @io: Structure arguments
* @nam: name
* Return: the value
*/
char *get_envr(io_t *io, const char *nam)
{
	list_t *nod = io->env;
	char *b;

	while (nod)
	{
		b = starts_with(nod->str, nam);
		if (b && *b)
			return (b);
		nod = nod->next;
	}
	return (NULL);
}

/**
* my_set_env - Initializ variable
* @io: Structure containarguments
* Return: Always 0
*/
int my_set_env(io_t *io)
{
	if (io->argc != 3)
	{
		eputting("You no sabi number of arguements\n");
		return (1);
	}
	if (set_env(io, io->argv[1], io->argv[2]))
		return (0);
	return (1);
}

/**
* my_unset_env - Remove variable
* @io: Structure ial arg
* Return: Always 0
*/
int my_unset_env(io_t *io)
{
	int j;

	if (io->argc == 1)
	{
		eputting("Your argument too small abeg few arguements.\n");
		return (1);
	}
	for (j = 1; j <= io->argc; j++)
		un_set_env(io, io->argv[j]);
	return (0);
}

/**
* popu_envr_list - populatlist
* @io: Structure arguments
* Return: Always 0
*/
int popu_envr_list(io_t *io)
{
	list_t *nod = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		_addnode(&nod, environ[j], 0);
	io->env = nod;
	return (0);
}
