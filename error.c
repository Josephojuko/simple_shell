#include "shell.h"

/**
* eputting - print string
* @str: the strprin
* Return: Always 0
*/
void eputting(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		putting_charact(str[j]);
		j++;
	}
}

/**
* putting_charact - writes the stderr
* @k: The print
* Return: On success 1 On failure, -1
*/
int putting_charact(char k)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (k == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (k != BUF_FLUSH)
		buf[j++] = k;
	return (1);
}

/**
* put_fd - writes the fd
* @k: The print
* @cod: The
* Return: On success 1. failure, -1
*/
int put_fd(char k, int cod)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (k == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(cod, buf, j);
		j = 0;
	}
	if (k != BUF_FLUSH)
		buf[j++] = k;
	return (1);
}

/**
* puts_fd - pristring
* @str: the striprinted
* @cod: the file
* Return: the number of chars put
*/
int puts_fd(char *str, int cod)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += put_fd(*str++, cod);
	}
	return (j);
}
