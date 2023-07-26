#include "shell.h"

/**
* get_his_tory_file - gets file
* @io: paramuct
* Return: allocated string containg history file
*/

char *get_his_tory_file(io_t *io)
{
	char *buf, *dirt;

	dirt = get_envr(io, "HOME=");
	if (!dirt)
		return (NULL);
	buf = malloc(sizeof(char) * (str_len(dirt) + str_len(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	str_cpy(buf, dirt);
	str_cat(buf, "/");
	str_cat(buf, HIST_FILE);
	return (buf);
}

/**
* write_his_tory - creates a file
* @io: the parame
* Return: 1 ose -1
*/
int write_his_tory(io_t *io)
{
	ssize_t cod;
	char *filnam = get_his_tory_file(io);
	list_t *nod = NULL;

	if (!filnam)
		return (-1);

	cod = open(filnam, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filnam);
	if (cod == -1)
		return (-1);
	for (nod = io->history; nod; nod = nod->next)
	{
		puts_fd(nod->str, cod);
		put_fd('\n', cod);
	}
	put_fd(BUF_FLUSH, cod);
	close(cod);
	return (1);
}

/**
* read_his_tory - file
* @io: the partruc
* Return: histcous, 0
*/
int read_his_tory(io_t *io)
{
	int w, las = 0, line_count = 0;
	ssize_t cod, rd_len, f_size = 0;
	struct stat st;
	char *buf = NULL, *filnam = get_his_tory_file(io);

	if (!filnam)
		return (0);

	cod = open(filnam, O_RDONLY);
	free(filnam);
	if (cod == -1)
		return (0);
	if (!fstat(cod, &st))
		f_size = st.st_size;
	if (f_size < 2)
		return (0);
	buf = malloc(sizeof(char) * (f_size + 1));
	if (!buf)
		return (0);
	rd_len = read(cod, buf, f_size);
	buf[f_size] = 0;
	if (rd_len <= 0)
		return (free(buf), 0);
	close(cod);
	for (w = 0; w < f_size; w++)
		if (buf[w] == '\n')
		{
			buf[w] = 0;
			build_hist_list(io, buf + las, line_count++);
			las = w + 1;
		}
	if (las != w)
		build_hist_list(io, buf + las, line_count++);
	free(buf);
	io->histcount = line_count;
	while (io->histcount-- >= HIST_MAX)
		delete_index(&(io->history), 0);
	re_number_history(io);
	return (io->histcount);
}

/**
* build_hist_list - adlist
* @io: Structure cont arg
* @buf: bbhhnujjjikj
* @line_count: the history linec
* Return: Always 0
*/
int build_hist_list(io_t *io, char *buf, int line_count)
{
	list_t *nod = NULL;

	if (io->history)
		nod = io->history;
	_addnode(&nod, buf, line_count);

	if (!io->history)
		io->history = nod;
	return (0);
}

/**
* re_number_history - renumbers changes
* @io: Structure
* Return: theunt
*/
int re_number_history(io_t *io)
{
	list_t *nod = io->history;
	int w = 0;

	while (nod)
	{
		nod->num = w++;
		nod = nod->next;
	}
	return (io->histcount = w);
}
