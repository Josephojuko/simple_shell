#include "shell.h"

/**
* _memset - fills yte
* @x: inter to
*@p: the byte th
*@u: the amou
*Return: (s) a po
*/
char *_memset(char *x, char p, unsigned int u)
{
	unsigned int w;

	for (w = 0; w < u; w++)
		x[w] = p;
	return (x);
}

/**
* ffree - frees trings
* @bb: of strings
*/
void ffree(char **bb)
{
	char **e = bb;

	if (!bb)
		return;
	while (*bb)
		free(*bb++);
	free(e);
}

/**
* _realloc - realmemory
* @ptr: pointer to
* @_oldsize: byte block
* @_newsize: byte block
* Return: pointer to
*/
void *_realloc(void *ptr, unsigned int _oldsize, unsigned int _newsize)
{
	char *b;

	if (!ptr)
		return (malloc(_newsize));
	if (!_newsize)
		return (free(ptr), NULL);
	if (_newsize == _oldsize)
		return (ptr);

	b = malloc(_newsize);
	if (!b)
		return (NULL);

	_oldsize = _oldsize < _newsize ? _oldsize : _newsize;
	while (_oldsize--)
		b[_oldsize] = ((char *)ptr)[_oldsize];
	free(ptr);
	return (b);
}
