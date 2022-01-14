#include "monty.h"
/**
 * fmod - Division of the second top element by the top element.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fmod(stack_t **stack, unsigned int line_number)
{
	int i;

	if (global.size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	fpop(stack, line_number);
	if (i == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= i;
}