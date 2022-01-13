#include "monty.h"
/**
 * get_func - Structure of the functions
 * @args: Arguments passed to the function
 * @pila: Header of the list(stack)
 * @line_number: Line data
 * Return: The text that can be read, or 1 if it fails
 */
void get_func(char *args, stack_t **pila, unsigned int line_number)
{
	int i = 0;
	instruction_t get_op[] = {
		{"push", fpush},
		{"pall", fpall},
		{"pint", fpint},
		{"pop", fpop},
		{NULL, NULL}};

	if (*args == '#')
	{
		return;
	}
	while (get_op[i].opcode != NULL)
	{
		if (strcmp(args, get_op[i].opcode) == 0)
		{
			get_op[i].f(pila, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args);
	exit(EXIT_FAILURE);
}
