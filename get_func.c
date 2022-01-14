#include "monty.h"
/**
 * get_func - Structure of the functions
 * @stack: Header of the list(stack)
 * @line: Line data
 * @args: Arguments passed to the function
 * Return: The text that can be read, or 1 if it fails
 */
void get_func(stack_t **stack, unsigned int line, char *args)
{
	int i = 0;
	instruction_t get_op[] = {
		{"push", fpush},
		{"pall", fpall},
		{"pint", fpint},
		{"pop", fpop},
		{"swap", fswap},
		{"fadd", fadd},
		{NULL, NULL}};

	if (*args == '#')
	{
		return;
	}
	while (get_op[i].opcode != NULL)
	{
		if (strcmp(args, get_op[i].opcode) == 0)
		{
			get_op[i].f(stack, line);
			return;

		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, args);
	exit(EXIT_FAILURE);
}
