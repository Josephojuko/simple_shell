#include "shell.h"

/**
* exiting_shell - shell
* @io: Structure argumen
* Return: exits with status
*/
int exiting_shell(io_t *io)
{
	int exitc;

	if (io->argv[1])
	{
		exitc = errant(io->argv[1]);
		if (exitc == -1)
		{
			io->status = 2;
			printed_errors(io, "number thief illegal: ");
			eputting(io->argv[1]);
			putting_charact('\n');
			return (1);
		}
		io->err_num = errant(io->argv[1]);
		return (-2);
	}
	io->err_num = -1;
	return (-2);
}

/**
* changing_directory - changes the process
* @io: Structure argument
* Return: Always 0
*/
int changing_directory(io_t *io)
{
	char *x, *dirt, buffer[1024];
	int chdirt;

	x = getcwd(buffer, 1024);
	if (!x)
		putter("Error my bro\n");
	if (!io->argv[1])
	{
		dirt = get_envr(io, "HOME=");
		if (!dirt)
			chdirt = chdir((dirt = get_envr(io, "PWD=")) ? dirt : "/");
		else
			chdirt = chdir(dirt);
	}
	else if (str_comp(io->argv[1], "-") == 0)
	{
		if (!get_envr(io, "OLDPWD="))
		{
			putter(x);
			_putchar('\n');
			return (1);
		}
		putter(get_envr(io, "OLDPWD=")), _putchar('\n');
		chdirt = chdir((dirt = get_envr(io, "OLDPWD=")) ? dirt : "/");
	}
	else
		chdirt = chdir(io->argv[1]);
	if (chdirt == -1)
	{
		printed_errors(io, "cannot change directory cd to ");
		eputting(io->argv[1]), putting_charact('\n');
	}
	else
	{
		set_env(io, "OLDPWD", get_envr(io, "PWD="));
		set_env(io, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
* changing_help - changes the cuocess
* @io: Structure containiarg
* Return: Always 0
*/
int changing_help(io_t *io)
{
	char **arg_ary;

	arg_ary = io->argv;
	putter("help call works. Funnted rest!!! \n");
	if (0)
		putter(*arg_ary);
	return (0);
}

