#include "shell.h"

/**
* in_buf - buffers ands
* @io: pauct
* @buf: addressfer
* @len: address ar
* Return: bytes
*/
ssize_t in_buf(io_t *io, char **buf, size_t *len)
{
	ssize_t f = 0;
	size_t lent_p = 0;

	if (!*len)
	{
		bfree((void **)io->cmd_buf);
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigint_Handler);
#if USE_GETLINE
		f = getline(buf, &lent_p, stdin);
#else
		f = _getline(io, buf, &lent_p);
#endif
		if (f > 0)
		{
			if ((*buf)[f - 1] == '\n')
			{
				(*buf)[f - 1] = '\0';
				f--;
			}
			io->linecount_flag = 1;
			rem_comm(*buf);
			build_hist_list(io, *buf, io->histcount++);
			if (str_chr(*buf, ';'))
			{
				*len = f;
				io->cmd_buf = buf;
			}
		}
	}
	return (f);
}

/**
* get_inp - gets a line wline
* @io: pastruct
* Return: byread
*/
ssize_t get_inp(io_t *io)
{
	static char *buf;
	static size_t w, x, len;
	ssize_t f = 0;
	char **buf_p = &(io->arg), *p;

	_putchar(BUF_FLUSH);
	f = in_buf(io, &buf, &len);
	if (f == -1)
		return (-1);
	if (len)
	{
		x = w;
		p = buf + w;

		chk_chain(io, buf, &x, w, len);
		while (x < len)
		{
			if (is_chin(io, buf, &x))
				break;
			x++;
		}

		w = x + 1;
		if (w >= len)
		{
			w = len = 0;
			io->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (str_len(p));
	}

	*buf_p = buf;
	return (f);
}

/**
* red_buf - readfer
* @io: paruct
* @buf: buer
* @w: sizeof iuhiuhu
* Return: f
*/
ssize_t red_buf(io_t *io, char *buf, size_t *w)
{
	ssize_t f = 0;

	if (*w)
		return (0);
	f = read(io->readfd, buf, READ_BUF_SIZE);
	if (f >= 0)
		*w = f;
	return (f);
}

/**
* _getline - gets the next line of i
* @io: paramete
* @ptrd: address of point
* @lent: size of preallocatedULL
* Return: x
*/
int _getline(io_t *io, char **ptrd, size_t *lent)
{
	static char buf[READ_BUF_SIZE];
	static size_t w, len;
	size_t k;
	ssize_t f = 0, x = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptrd;
	if (p && lent)
		x = *lent;
	if (w == len)
		w = len = 0;

	f = red_buf(io, buf, &len);
	if (f == -1 || (f == 0 && len == 0))
		return (-1);

	c = str_chr(buf + w, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, x, x ? x + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (x)
		strn_cat(new_p, buf + w, k - w);
	else
		strn_cpy(new_p, buf + w, k - w + 1);

	x += k - w;
	w = k;
	p = new_p;

	if (lent)
		*lent = x;
	*ptrd = p;
	return (x);
}

/**
* sigint_Handler - bloc
* @sign_num: the signal
* Return: void
*/
void sigint_Handler(__attribute__((unused))int sign_num)
{
	putter("\n");
	putter("$ ");
	_putchar(BUF_FLUSH);
}
