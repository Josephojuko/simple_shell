#include "shell.h"
/**
* intive - returns  mode
* @io: strress
* Return: 1 iftherwise
*/
int intive(io_t *io)
{
	return (isatty(STDIN_FILENO) && io->readfd <= 2);
}
/**
* delimiter - checkselimeter
* @k: jidfvjfdkfgkdfgjfg+ck
* @limit: the string
* Return: 1 true, 0  false
*/
int delimiter(char k, char *limit)
{
	while (*limit)
		if (*limit++ == k)
			return (1);
	return (0);
}
/**
* alphabet - checkslphabet
* @k: The input
* Return: 1 if c is , 0 othe
*/
int alphabet(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}
/**
* strtoint - coni nteger
* @x: the strrted
* Return: 0 if no numbers , converted nwise
*/
int strtoint(char *x)
{
	int l, sigma = 1, plague = 0, outputer;
	unsigned int resulter = 0;

	for (l = 0; x[l] != '\0' && plague != 2; l++)
	{
		if (x[l] == '-')
			sigma *= -1;
		if (x[l] >= '0' && x[l] <= '9')
		{
			plague = 1;
			resulter *= 10;
			resulter += (x[l] - '0');
		}
		else if (plague == 1)
			plague = 2;
	}
	if (sigma == -1)
		outputer = -resulter;
	else
		outputer = resulter;
	return (outputer);
}
