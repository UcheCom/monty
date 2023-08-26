#include "monty.h"

dat_t uvar = UVAR_INIT;

/**
 * monty - this is the helper function for main func
 * @args: pointer to struct of arguments from main
 *
 * Description: opens and reads from the file
 * containing the opcodes, and calls the function
 * that will find the corresponding executing function
 */
void monty(ags_t *args)
{
	size_t len = 0;
	int get = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (args->argc != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	uvar.ptr = fopen(args->argv, "r");
	if (!uvar.ptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args->argv);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		/*args->line_number++;
		get = getline(&(uvar.line), &len, uvar.ptr);
		if (get < 0)
			break;
		uvar.toks = strtow(uvar.line);
		if (uvar.toks[0] == NULL || uvar.toks[0][0] == '#')
		{
			free_all(0);
			continue;
		}
		code_func = _getfunc(uvar.toks);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->line_number, uvar.toks[0]);
			free_all(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(uvar.stack), args->line_number);
		free_all(0);
	}
	free_all(1);
}*/

/**
 * main - entry point for monty bytecode interpreter
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char *av[])
{
	ags_t args;

	args.argv = av[1];
	args.argc = ac;
	args.line_number = 0;

	monty(&args);

	return (EXIT_SUCCESS);
}
