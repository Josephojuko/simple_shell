#include "shell.h"

/**
* str_cpy - coping
* @dest: tdeion
* @src: th
* Return: poion
*/
char *str_cpy(char *dest, char *src)
{
	int w = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[w])
	{
		dest[w] = src[w];
		w++;
	}
	dest[w] = 0;
	return (dest);
}

/**
* str_dup - dupstring
* @str: the strincate
* Return: pointer string
*/
char *str_dup(const char *str)
{
	int lent = 0;
	char *rat;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lent++;
	rat = malloc(sizeof(char) * (lent + 1));
	if (!rat)
		return (NULL);
	for (lent++; lent--;)
		rat[lent] = *--str;
	return (rat);
}

/**
* putter - prints anring
* @str: the strinbe printed
* Return: 0
*/
void putter(char *str)
{
	int w = 0;

	if (!str)
		return;
	while (str[w] != '\0')
	{
		_putchar(str[w]);
		w++;
	}
}

/**
* _putchar - writes dout
* @k: Theprint
* Return: On success 1.
*/
int _putchar(char k)
{
	static int w;
	static char buf[WRITE_BUF_SIZE];

	if (k == BUF_FLUSH || w >= WRITE_BUF_SIZE)
	{
		write(1, buf, w);
		w = 0;
	}
	if (k != BUF_FLUSH)
		buf[w++] = k;
	return (1);
}
