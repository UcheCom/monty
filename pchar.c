#include "monty.h"

/**
 * pchar - this prints the char at the top of the stack
 * @head: double pointer of the head of the stack
 * @line: the current line number
 *
 * Return: void
 */
void pchar(stack_t **head, unsigned int line)
{
	if (!head || !*head)
	{
		fprintf(stderr, PCHAR_FAIL, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, PCHAR_RANGE, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
