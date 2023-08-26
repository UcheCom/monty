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
