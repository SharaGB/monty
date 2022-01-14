#include "monty.h"
/**
 * f_mod - Division of the second top element by the top element.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (global.size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	f_pop(stack, line_number);
	if (i == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= i;
}

/**
 * f_rotl - Rotates the stack to the top.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (*stack)
	{
		*stack = (*stack)->next;
	}
}