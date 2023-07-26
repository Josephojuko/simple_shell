#include "shell.h"

/**
* hsh - main shell loop
* @io: the paratruct
* @v: the argumen()
* Return: 0 on su
*/
int hsh(io_t *io, char **v)
{
	ssize_t f = 0;
	int built_ret = 0;

	while (f != -1 && built_ret != -2)
	{
		cl_info(io);
		if (intive(io))
			putter("$ ");
		putting_charact(BUF_FLUSH);
		f = get_inp(io);
		if (f != -1)
		{
			s_info(io, v);
			built_ret = fnd_builtin(io);
			if (built_ret == -1)
				find_cmd(io);
		}
		else if (intive(io))
			_putchar('\n');
		fr_info(io, 0);
	}
	write_his_tory(io);
	fr_info(io, 1);
	if (!intive(io) && io->status)
		exit(io->status);
	if (built_ret == -2)
	{
		if (io->err_num == -1)
			exit(io->status);
		exit(io->err_num);
	}
	return (built_ret);
}

/**
* fnd_builtin - finds mand
* @io: the parameter & reruct
* Return: jjgfkgflllkk
*/
int fnd_builtin(io_t *io)
{
	int w, built_in_rete = -1;
	builtin_table builtintbl[] = {
		{"exiting", exiting_shell},
		{"envr", my_env},
		{"helper", changing_help},
		{"historian", his_tory},
		{"setenvr", my_set_env},
		{"unsetenvr", my_unset_env},
		{"cdir", changing_directory},
		{"ali_as", my_alias},
		{NULL, NULL}
	};

	for (w = 0; builtintbl[w].type; w++)
		if (str_comp(io->argv[0], builtintbl[w].type) == 0)
		{
			io->line_count++;
			built_in_rete = builtintbl[w].func(io);
			break;
		}
	return (built_in_rete);
}

/**
* find_cmd - finds PATH
* @io: the parametestruct
* Return: void
*/
void find_cmd(io_t *io)
{
	char *pth = NULL;
	int w, c;

	io->path = io->argv[0];
	if (io->linecount_flag == 1)
	{
		io->line_count++;
		io->linecount_flag = 0;
	}
	for (w = 0, c = 0; io->arg[w]; w++)
		if (!delimiter(io->arg[w], " \t\n"))
			c++;
	if (!c)
		return;

	pth = _findpath(io, get_envr(io, "PATH="), io->argv[0]);
	if (pth)
	{
		io->path = pth;
		fork_cmd(io);
	}
	else
	{
		if ((intive(io) || get_envr(io, "PATH=")
			|| io->argv[0][0] == '/') && _iscmd(io, io->argv[0]))
			fork_cmd(io);
		else if (*(io->arg) != '\n')
		{
			io->status = 127;
			printed_errors(io, "not getout jo nonsensense found\n");
		}
	}
}

/**
* fork_cmd - forks run cmd
* @io: the paramestruct
* Return: void
*/
void fork_cmd(io_t *io)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(io->path, io->argv, get_envir(io)) == -1)
		{
			fr_info(io, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		perror("Error:");
	}
	else
	{
		wait(&(io->status));
		if (WIFEXITED(io->status))
		{
			io->status = WEXITSTATUS(io->status);
			if (io->status == 126)
				printed_errors(io, "Permission you are not allowed denied\n");
		}
	}
}
