#include "shell.h"

/**
* **str_tow - ss a string into
* @str: th string
* @p: thing
* Return: array
*/

char **str_tow(char *str, char *p)
{
	int w, x, y, z, numwrds = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!p)
		p = " ";
	for (w = 0; str[w] != '\0'; w++)
		if (!delimiter(str[w], p) && (delimiter(str[w + 1], p) || !str[w + 1]))
			numwrds++;

	if (numwrds == 0)
		return (NULL);
	s = malloc((1 + numwrds) * sizeof(char *));
	if (!s)
		return (NULL);
	for (w = 0, x = 0; x < numwrds; x++)
	{
		while (delimiter(str[w], p))
			w++;
		y = 0;
		while (!delimiter(str[w + y], p) && str[w + y])
			y++;
		s[x] = malloc((y + 1) * sizeof(char));
		if (!s[x])
		{
			for (y = 0; y < x; y++)
				free(s[y]);
			free(s);
			return (NULL);
		}
		for (z = 0; z < y; z++)
			s[x][z] = str[w++];
		s[x][z] = 0;
	}
	s[x] = NULL;
	return (s);
}

/**
* **str_tow2 - splitords
* @str: ttring
* @p: the delimeter
* Return: a pointer
*/
char **str_tow2(char *str, char p)
{
	int w, x, y, z, numwrds = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (w = 0; str[w] != '\0'; w++)
		if ((str[w] != p && str[w + 1] == p) ||
		    (str[w] != p && !str[w + 1]) || str[w + 1] == p)
			numwrds++;
	if (numwrds == 0)
		return (NULL);
	s = malloc((1 + numwrds) * sizeof(char *));
	if (!s)
		return (NULL);
	for (w = 0, x = 0; x < numwrds; x++)
	{
		while (str[w] == p && str[w] != p)
			w++;
		y = 0;
		while (str[w + y] != p && str[w + y] && str[w + y] != p)
			y++;
		s[x] = malloc((y + 1) * sizeof(char));
		if (!s[x])
		{
			for (y = 0; y < x; y++)
				free(s[y]);
			free(s);
			return (NULL);
		}
		for (z = 0; z < y; z++)
			s[x][z] = str[w++];
		s[x][z] = 0;
	}
	s[x] = NULL;
	return (s);
}
