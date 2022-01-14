#include "monty.h"
/**
 * fadd - Adds the top two elements of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fadd(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;

    if (!tmp || !(*stack)->prev)
    {
        error_handler("can't add, stack too short", line_number);
    }
    (tmp->prev)->n = tmp->n + (tmp->prev)->n;
	fpop(stack, line_number);
}

/**
 * fsub - Subtracts the top element from the second top element.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fsub(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;

    if (!tmp || !(*stack)->prev)
    {
        error_handler("can't sub, stack too short", line_number);
    }
    (tmp->prev)->n = (tmp->prev)->n - tmp->n;
	fpop(stack, line_number);
}

/**
 * mul - Function that adds the top two elements of the stack
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
		mul_error(line_number);

	(tmp->prev)->n = (tmp->prev)->n * tmp->n;
	pop(stack, line_number);
}

/**
 * _div - Function that adds the top two elements of the stack
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
		div_error(line_number);

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->prev->n = tmp->prev->n / tmp->n;
	pop(stack, line_number);
}

/**
 * mod - Function that adds the top two elements of the stack
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
		mod_error(line_number);

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->prev->n = tmp->prev->n % tmp->n;
	pop(stack, line_number);
}

/**
 * nop - Doesnt do anything
 * @stack: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}