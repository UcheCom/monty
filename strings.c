#include "monty.h"

/**
 * _wordcount - helper function that counts the number of words in a string
 * @s: string to count
 *
 * Return: number of words
 */
int _wordcount(char *s)
{
	int flag, c, x;

	flag = 0;
	x = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			x++;
		}
	}

	return (x);
}
/**
 * strtow - splits/parses a string into words
 * @s: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *s)
{
	char **max, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(s);
	words = _wordcount(s);
	if (words == 0)
		return (NULL);

	max = (char **) malloc(sizeof(char *) * (words + 1));
	if (max == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (isspace(s[i]) || s[i] == '\0' || s[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = s[start++];
				*tmp = '\0';
				max[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	max[k] = NULL;

	return (max);
}
