#include "shell.h"

/**
* cl_info - initializes io
* @io: stess
*/
void cl_info(io_t *io)
{
	io->arg = NULL;
	io->argv = NULL;
	io->path = NULL;
	io->argc = 0;
}

/**
* s_info - initializeuct
* @io: struess
* @ev: argvector
*/
void s_info(io_t *io, char **ev)
{
	int j = 0;

	io->fname = ev[0];
	if (io->arg)
	{
		io->argv = str_tow(io->arg, " \t");
		if (!io->argv)
		{

			io->argv = malloc(sizeof(char *) * 2);
			if (io->argv)
			{
				io->argv[0] = str_dup(io->arg);
				io->argv[1] = NULL;
			}
		}
		for (j = 0; io->argv && io->argv[j]; j++)
			;
		io->argc = j;

		replace_ali_as(io);
		rep_lace_vars(io);
	}
}

/**
* fr_info - freeselds
* @io: strucs
* @al: true if frds
*/
void fr_info(io_t *io, int al)
{
	ffree(io->argv);
	io->argv = NULL;
	io->path = NULL;
	if (al)
	{
		if (!io->cmd_buf)
			free(io->arg);
		if (io->env)
			fr_list(&(io->env));
		if (io->history)
			fr_list(&(io->history));
		if (io->alias)
			fr_list(&(io->alias));
		ffree(io->environ);
			io->environ = NULL;
		bfree((void **)io->cmd_buf);
		if (io->readfd > 2)
			close(io->readfd);
		_putchar(BUF_FLUSH);
	}
}
