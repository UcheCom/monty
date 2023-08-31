#include  "monty.h"

dat_t uvar;

/**
 * main - entry point for monty bytecode interpreter
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	FILE *ptr;
	size_t size = 256;
	ssize_t _numread = 0;
	void (*f)(stack_t **stack, unsigned int line_number);
	char *tok = NULL;

	if (ac != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}
	ptr = fopen(av[1], "r");
	if (!ptr)
	{
		fprintf(stderr, FILE_ERROR, av[1]);
		exit(EXIT_FAILURE);
	}
	m_initvar(ptr);
	_numread = _getline(&uvar.buff, &size, ptr);
	while (_numread != -1)
	{
		tok = strtok(uvar.buff, " \t\n");
		if (tok && tok[0] != '#')
		{
			f = _getfunc(tok);
			if (!f)
			{
			fprintf(stderr, "L%u ", uvar.line);
			fprintf(stderr, "unknown instruction %s\n", tok);
			_freevar();
			exit(EXIT_FAILURE);
			}
			uvar.arg = strtok(NULL, " \t\n");
			/*f(&uvar.head, uvar.line);*/
		}
		_numread = _getline(&uvar.buff, &size, ptr);
		uvar.line++;
	}
	_freevar();
	return (0);
}
