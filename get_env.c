#include "shell.h"

/**
* get_envir - retur viron
* @io: Structure cont arg
* Return: Always 0
*/
char **get_envir(io_t *io)
{
	if (!io->environ || io->env_changed)
	{
		io->environ = list_to_strings(io->env);
		io->env_changed = 0;
	}

	return (io->environ);
}

/**
* un_set_env - Remove variable
* @io: Structure containi
* Return: 1 on de, 0 otherwise
* @var: the stringoperty
*/
int un_set_env(io_t *io, char *var)
{
	list_t *nod = io->env;
	size_t j = 0;
	char *b;

	if (!nod || !var)
		return (0);

	while (nod)
	{
		b = starts_with(nod->str, var);
		if (b && *b == '=')
		{
			io->env_changed = delete_index(&(io->env), j);
			j = 0;
			nod = io->env;
			continue;
		}
		nod = nod->next;
		j++;
	}
	return (io->env_changed);
}

/**
* set_env - get out
* @io: Structure conargumen
* @var: the string enerty
* @val: the string
*  Return: Always 0
*/
int set_env(io_t *io, char *var, char *val)
{
	char *buff = NULL;
	list_t *nod;
	char *b;

	if (!var || !val)
		return (0);

	buff = malloc(str_len(var) + str_len(val) + 2);
	if (!buff)
		return (1);
	str_cpy(buff, var);
	str_cat(buff, "=");
	str_cat(buff, val);
	nod = io->env;
	while (nod)
	{
		b = starts_with(nod->str, var);
		if (b && *b == '=')
		{
			free(nod->str);
			nod->str = buff;
			io->env_changed = 1;
			return (0);
		}
		nod = nod->next;
	}
	_addnode(&(io->env), buff, 0);
	free(buff);
	io->env_changed = 1;
	return (0);
}
