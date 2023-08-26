#include "monty.h"

/**
 * free_all - this is the memory handling function
 * @f_all: flag to indicate what to free
 */
void free_all(int f_all)
{
	if (uvar.line)
	{
		free(uvar.line);
		uvar.line = NULL;
		e_free(uvar.toks);
		uvar.toks = NULL;
	}

	if (f_all)
	{
		if (uvar.stack)
		{
			free_dlistint(uvar.stack);
			uvar.stack = NULL;
		}
		if (uvar.ptr)
		{
			fclose(uvar.ptr);
			uvar.ptr = NULL;
		}
	}
}

/**
 * e_free - frees arrays of strings
 * @args: strings to be freed
 */
void e_free(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}
