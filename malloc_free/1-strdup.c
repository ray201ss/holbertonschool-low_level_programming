#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space containing a copy
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if str is NULL or failed
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	dup = malloc((len + 1) * sizeof(char));

	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		dup[i] = str[i];
	}

	return (dup);
}
