#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>	/* prinf, fprinf, stderr, FILE, feof, fopen*/
#include <stdlib.h> /* exit, malloc, free, atoi*/
#include <string.h> /* strtok*/
#include <ctype.h>	/* isdigit*/
#include <math.h>
#include <limits.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - Variable global
 * @data: Determine if in stack vs queue mode
 * @size: length of the stack
 */
typedef struct global_s
{
	int data;
	size_t size;
} global_t;

#define STACK 0
#define QUEUE 1

extern global_t global;
void get_func(char *op, stack_t **stack, unsigned int line_number);
void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number __attribute__((unused)));
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
void f_nop(stack_t **stack, unsigned int line_number);
void f_sub(stack_t **stack, unsigned int line_number);
void f_div(stack_t **stack, unsigned int line_number);
void f_mul(stack_t **stack, unsigned int line_number);
void f_mod(stack_t **stack, unsigned int line_number);

FILE *f_open(char *argv);
int is_digit(char *digit);
stack_t *add_node(stack_t **stack, const int n);
void free_stack(int fre, void *args);
void frees(int fre, void *args);

#endif /* MONTY_H */
