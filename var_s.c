#include "shell.h"

/**
* is_chin - testimeter
* @io: tht
* @buf: thfer
* @b: address
* Return: er, 0 otherwise
*/
int is_chin(io_t *io, char *buf, size_t *b)
{
	size_t x = *b;

	if (buf[x] == '|' && buf[x + 1] == '|')
	{
		buf[x] = 0;
		x++;
		io->cmd_buf_type = CMD_OR;
	}
	else if (buf[x] == '&' && buf[x + 1] == '&')
	{
		buf[x] = 0;
		x++;
		io->cmd_buf_type = CMD_AND;
	}
	else if (buf[x] == ';')
	{
		buf[x] = 0;
		io->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*b = x;
	return (1);
}

/**
* chk_chain - checkstatus
* @io: fgbgggggggggggggggggg
* @buf: theer
* @b: address of cuf
* @w: startingbuf
* @len: lbuf
* Return: Void
*/
void chk_chain(io_t *io, char *buf, size_t *b, size_t w, size_t len)
{
	size_t x = *b;

	if (io->cmd_buf_type == CMD_AND)
	{
		if (io->status)
		{
			buf[w] = 0;
			x = len;
		}
	}
	if (io->cmd_buf_type == CMD_OR)
	{
		if (!io->status)
		{
			buf[w] = 0;
			x = len;
		}
	}

	*b = x;
}

/**
* replace_ali_as - replacetring
* @io: struct
* Return: 1 if d, 0 orwise
*/
int replace_ali_as(io_t *io)
{
	int w;
	list_t *nod;
	char *b;

	for (w = 0; w < 10; w++)
	{
		nod = node_startswith(io->alias, io->argv[0], '=');
		if (!nod)
			return (0);
		free(io->argv[0]);
		b = str_chr(nod->str, '=');
		if (!b)
			return (0);
		b = str_dup(b + 1);
		if (!b)
			return (0);
		io->argv[0] = b;
	}
	return (1);
}

/**
* rep_lace_vars - string
* @io: hjvfjfjfdnndt
* Return: 1 ifd, 0 othse
*/
int rep_lace_vars(io_t *io)
{
	int w = 0;
	list_t *nod;

	for (w = 0; io->argv[w]; w++)
	{
		if (io->argv[w][0] != '$' || !io->argv[w][1])
			continue;

		if (!str_comp(io->argv[w], "$?"))
		{
			replace_string(&(io->argv[w]),
				str_dup(conv_numb(io->status, 10, 0)));
			continue;
		}
		if (!str_comp(io->argv[w], "$$"))
		{
			replace_string(&(io->argv[w]),
				str_dup(conv_numb(getpid(), 10, 0)));
			continue;
		}
		nod = node_startswith(io->env, &io->argv[w][1], '=');
		if (nod)
		{
			replace_string(&(io->argv[w]),
				str_dup(str_chr(nod->str, '=') + 1));
			continue;
		}
		replace_string(&io->argv[w], str_dup(""));

	}
	return (0);
}

/**
* replace_string - replg
* @od: addrstring
* @nw: ne
* Return: 1 id, 0 se
*/
int replace_string(char **od, char *nw)
{
	free(*od);
	*od = nw;
	return (1);
}
