#include "monty.h"

/**
 * _realloc - this reallocates memory
 * @ptr: pointer to the memory space
 * @size: initial size
 * @new_size: new size
 *
 * Return: the pointer tot he new space allocated
 */
void *_realloc(void *ptr, size_t size, size_t new_size)
{
	void *new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (new_size < size)
		memcpy(new_ptr, ptr, new_size);
	else
		memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

/**
 * _getline - read a line from the stream
 * @line: pointer to the line
 * @n: pointer to the size of the buffer pointed by the line
 * @stream: stream from which the line will be readed
 *
 * Return: the number of character readed or -1 on failure
 */
ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	char buff[256];

	if (line == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*line == NULL)
	{
		*n = sizeof(buff);
		*line = malloc(*n);
		if (!(*line))
			return (-1);
	}
	(*line)[0] = '\0';
	while (fgets(buff, sizeof(buff), stream) != NULL)
	{
		if (*n - strlen(*line) < sizeof(buff))
		{
			*n *= 2;
			*line = _realloc(*line, *n / 2, *n);
			if (!(*line))
			{
				free(line);
				return (-1);
			}
		}
		strcat(*line, buff);
		if ((*line)[strlen(*line) - 1] == '\n')
			return (strlen(*line));
	}
	return (-1);
}
