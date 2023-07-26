#include "shell.h"

/**
* str_len - returns string
* @x: the string check
* Return: instring
*/
int str_len(char *x)
{
	int w = 0;

	if (!x)
		return (0);

	while (*x++)
		w++;
	return (w);
}

/**
* str_comp - perfor strangs.
* @x1: the strang
* @x2: the strang
* Return: negatizero if s1 == s2
*/
int str_comp(char *x1, char *x2)
{
	while (*x1 && *x2)
	{
		if (*x1 != *x2)
			return (*x1 - *x2);
		x1++;
		x2++;
	}
	if (*x1 == *x2)
		return (0);
	else
		return (*x1 < *x2 ? -1 : 1);
}

/**
* starts_with - checks ystack
* @hatack: striearch
* @nele: the ind
* Return: address of neck or NULL
*/
char *starts_with(const char *hatack, const char *nele)
{
	while (*nele)
		if (*nele++ != *hatack++)
			return (NULL);
	return ((char *)hatack);
}

/**
* str_cat - concatstrings
* @dest: the desuffer
* @src: thebuffer
* Return: pointer
*/
char *str_cat(char *dest, char *src)
{
	char *rat = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (rat);
}

