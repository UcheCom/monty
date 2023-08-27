#include "monty.h"

/**
 * _initvar - this initializes the global variable
 * @ptr: file descriptor pointer of the opened file
 *
 * Return: void
 */
void _initvar(FILE *ptr)
{
	uvar.line = 1;
	uvar.ptr = ptr;
	uvar.head = NULL;
	uvar.buff = NULL;
	uvar.arg = NULL;
	uvar.qs_flag = 1;
}

/**
 * _freevar - this frees the global variable
 *
 * Return: void
 */
void _freevar(void)
{
	free_dlistint(uvar.head);
	free(uvar.buff);
	fclose(uvar.ptr);
}
