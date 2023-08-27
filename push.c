#include "monty.h"

/**
 * push - this pushes data to a stack
 * @head: double pointer the head of the stack
 * @line: current line number
 *
 */
void push(stack_t **head, unsigned int line)
{
	int n, i;

	if (!uvar.arg)
	{
		fprintf(stderr, PUSH_FAIL, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	for (i = 0; uvar.arg[i] != '\0'; i++)
	{
		if (!isdigit(uvar.arg[i]) && uvar.arg[i] != '-')
		{
			fprintf(stderr, PUSH_FAIL, line);
			_freevar();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(uvar.arg);
	if (uvar.qs_flag == 1)
		add_dnodeint(head, n);
	else if (uvar.qs_flag == 0)
		add_dnodeint_end(head, n);
}
