#include "monty.h"
/**
 * get_func - Structure of the functions
 * @stack: Header of the list(stack)
 * @line_number: Line data
 * @args: Arguments passed to the function
 * Return: The text that can be read, or 1 if it fails
 */
void get_func(char *args, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t get_op[] = {
		{"push", fpush},
		{"pall", fpall},
		{"pint", fpint},
		{"pop", fpop},
		{"swap", fswap},
		{"add", f_add},
		{"nop", fnop},
		{"sub", f_sub},
		{"div", f_div},
		{"mod", f_mod},
		{NULL, NULL}};

	while (get_op[i].opcode != NULL)
	{
		if (strcmp(args, get_op[i].opcode) == 0)
		{
			get_op[i].f(stack, line_number);
			return;

		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args);
	exit(EXIT_FAILURE);
}
