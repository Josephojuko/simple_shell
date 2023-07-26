#include "shell.h"

/**
* strn_cpy - coptring
* @det: the destination to
* @srct: the string
* @u: the amount ofcopied
* Return: thstring
*/
char *strn_cpy(char *det, char *srct, int u)
{
	int i, j;
	char *x = det;

	i = 0;
	while (srct[i] != '\0' && i < u - 1)
	{
		det[i] = srct[i];
		i++;
	}
	if (i < u)
	{
		j = i;
		while (j < u)
		{
			det[j] = '\0';
			j++;
		}
	}
	return (x);
}

/**
* strn_cat - concatetrings
* @det: the ftring
* @srct: thering
* @u: the amount of bytes used
* Return: the cd string
*/
char *strn_cat(char *det, char *srct, int u)
{
	int i, j;
	char *x = det;

	i = 0;
	j = 0;
	while (det[i] != '\0')
		i++;
	while (srct[j] != '\0' && j < u)
	{
		det[i] = srct[j];
		i++;
		j++;
	}
	if (j < u)
		det[i] = '\0';
	return (x);
}

/**
* str_chr - locates a ring
* @x: the strinrsed
* @k: the characterok for
* Return: (x) a pointer t
*/
char *str_chr(char *x, char k)
{
	do {
		if (*x == k)
			return (x);
	} while (*x++ != '\0');

	return (NULL);
}
