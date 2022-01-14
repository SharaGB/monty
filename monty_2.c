#include "monty.h"
/**
 * f_add - Adds the top two elements of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (global.size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i += (*stack)->n;
	fpop(stack, line_number);
	(*stack)->n += i;
}

/**
 * fnop - The opcode nop doesn’t do anything.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fnop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * f_sub - Subtracts the top element from the second top element.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	int i;

	if (global.size < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	fpop(stack, line_number);
	(*stack)->n -= i;
}

/**
 * f_div - Divides the second top element by the top element.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	int i;

	if (global.size < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	fpop(stack, line_number);
	if (i == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= i;
}

/**
 * f_mul - Multiplies the second top element with the top element.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
	int i;

	if (global.size < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	fpop(stack, line_number);
	(*stack)->n *= i;
}
