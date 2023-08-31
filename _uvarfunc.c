#include "monty.h"

/**
 * m_initvar - this initializes the global variable
 * @ptr: file descriptor pointer of the opened file
 *
 * Return: void
 */
void m_initvar(FILE *ptr)
{
	uvar.ptr = ptr;
	uvar.head = NULL;
	uvar.buff = NULL;
	uvar.arg = NULL;
	uvar.qs_flag = 1;
	uvar.line = 1;
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
