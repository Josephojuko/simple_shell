#include "shell.h"

/**
* errant - cointeger
* @x: therted
* Return: 0 if no n-1 onfailure
*/
int errant(char *x)
{
	int j = 0;
	unsigned long int rest = 0;

	if (*x == '+')
		x++;
	for (j = 0;  x[j] != '\0'; j++)
	{
		if (x[j] >= '0' && x[j] <= '9')
		{
			rest *= 10;
			rest += (x[j] - '0');
			if (rest > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rest);
}

/**
* printed_errors - mhjuhiggjghhkjlae
* @io: the ter & rstruct
* @easter: string contatype
* Return: 0 if no numbers -1 on failure
*/
void printed_errors(io_t *io, char *easter)
{
	eputting(io->fname);
	eputting(": ");
	_printed(io->line_count, STDERR_FILENO);
	eputting(": ");
	eputting(io->argv[0]);
	eputting(": ");
	eputting(easter);
}

/**
* _printed - function prints a decima
* @in: thut
* @cod: the file
* Return: number of characters printed
*/
int _printed(int in, int cod)
{
	int (*__putchar)(char) = _putchar;
	int j, counter = 0;
	unsigned int abs, curt;

	if (cod == STDERR_FILENO)
		__putchar = putting_charact;
	if (in < 0)
	{
		abs = -in;
		__putchar('-');
		counter++;
	}
	else
		abs = in;
	curt = abs;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (abs / j)
		{
			__putchar('0' + curt / j);
			counter++;
		}
		curt %= j;
	}
	__putchar('0' + curt);
	counter++;

	return (counter);
}

/**
* conv_numb - converter
* @numb: nu
* @bas: base
* @flags: argument flags
* Return: string of
*/
char *conv_numb(long int numb, int bas, int flags)
{
	static char *ary;
	static char buffer[50];
	char sigma = 0;
	char *pitr;
	unsigned long n = numb;

	if (!(flags & CONVERT_UNSIGNED) && numb < 0)
	{
		n = -numb;
		sigma = '-';

	}
	ary = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pitr = &buffer[49];
	*pitr = '\0';

	do	{
		*--pitr = ary[n % bas];
		n /= bas;
	} while (n != 0);

	if (sigma)
		*--pitr = sigma;
	return (pitr);
}

/**
* rem_comm - function replf '#' with '\0'
* @buff: address of the odify
* Return: Always 0;
*/
void rem_comm(char *buff)
{
	int j;

	for (j = 0; buff[j] != '\0'; j++)
		if (buff[j] == '#' && (!j || buff[j - 1] == ' '))
		{
			buff[j] = '\0';
			break;
		}
}

