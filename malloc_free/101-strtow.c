#include "main.h"
#include <stdlib.h>

int count_words(char *str);
char *copy_word(char *str, int start, int len);
void free_words(char **words, int count);

/**
 * count_words - counts the number of words in a string
 * @str: string to count words in
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	return (count);
}

/**
 * copy_word - copies a word from string
 * @str: source string
 * @start: start index
 * @len: length of word
 * Return: pointer to new word
 */
char *copy_word(char *str, int start, int len)
{
	char *word;
	int j;

	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	for (j = 0; j < len; j++)
		word[j] = str[start + j];
	word[j] = '\0';
	return (word);
}

/**
 * free_words - frees array of words
 * @words: array to free
 * @count: number of words to free
 */
void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);
	free(words);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 * Return: pointer to array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, k = 0, wc, wlen;

	if (str == NULL || *str == '\0')
		return (NULL);
	wc = count_words(str);
	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			wlen = 0;
			while (str[i + wlen] != ' ' && str[i + wlen] != '\0')
				wlen++;
			words[k] = copy_word(str, i, wlen);
			if (words[k] == NULL)
			{
				free_words(words, k);
				return (NULL);
			}
			k++;
			i += wlen;
		}
		else
			i++;
	}
	words[k] = NULL;
	return (words);
}
