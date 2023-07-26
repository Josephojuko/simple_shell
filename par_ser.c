#include "shell.h"

/**
* _iscmd - determines immand
* @io: the truct
* @pth: path
* Return: 1 if, 0 otse
*/
int _iscmd(io_t *io, char *pth)
{
	struct stat st;

	(void)io;
	if (!pth || stat(pth, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
* _dupchars - duplers
* @pthstr: the PATH
* @star: starting
* @stp: s index
* Return: pointer to new buffer
*/
char *_dupchars(char *pthstr, int star, int stp)
{
	static char buf[1024];
	int w = 0, c = 0;

	for (c = 0, w = star; w < stp; w++)
		if (pthstr[w] != ':')
			buf[c++] = pthstr[w];
	buf[c] = 0;
	return (buf);
}

/**
* _findpath - finds thistring
* @io: thect
* @pthstr: the PATH
* @cmd: the nd
* Return: full ULL
*/
char *_findpath(io_t *io, char *pthstr, char *cmd)
{
	int w = 0, curt_post = 0;
	char *pth;

	if (!pthstr)
		return (NULL);
	if ((str_len(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (_iscmd(io, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pthstr[w] || pthstr[w] == ':')
		{
			pth = _dupchars(pthstr, curt_post, w);
			if (!*pth)
				str_cat(pth, cmd);
			else
			{
				str_cat(pth, "/");
				str_cat(pth, cmd);
			}
			if (_iscmd(io, pth))
				return (pth);
			if (!pthstr[w])
				break;
			curt_post = w;
		}
		w++;
	}
	return (NULL);
}
