#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string
 * @str: string to count words in
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count;

	count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, wc, word_len;

	if (str == NULL || *str == '\0')
		return (NULL);
	wc = count_words(str);
	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			word_len = 0;
			j = i;
			while (str[j] != ' ' && str[j] != '\0')
			{
				word_len++;
				j++;
			}
			words[k] = malloc((word_len + 1) * sizeof(char));
			if (words[k] == NULL)
			{
				for (len = 0; len < k; len++)
					free(words[len]);
				free(words);
				return (NULL);
			}
			for (j = 0; j < word_len; j++)
				words[k][j] = str[i + j];
			words[k][j] = '\0';
			k++;
			i += word_len;
		}
		else
			i++;
	}
	words[k] = NULL;
	return (words);
}
