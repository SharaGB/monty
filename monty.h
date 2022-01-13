#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>	/* prinf, fprinf, stderr, FILE, feof, fopen*/
#include <stdlib.h> /* exit, malloc, free, atoi*/
#include <string.h> /* strtok*/
#include <ctype.h>	/* isdigit*/

#define DELIMITER " \t\n"
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
 * struct global_structure - extern global variable.
 * @data: Data readed from the file.
 * @array_st: Array.
 * @fd_st: file readed.
 *
typedef struct global_s
{
int data;
char **array;
} global_t;

extern global_t global;*/

void get_func(char *args, stack_t **pila, unsigned int line_number);
void fpush(stack_t **pila, unsigned int line_number);
void fpall(stack_t **pila, unsigned int line_number __attribute__((unused)));
void fpint(stack_t **pila, unsigned int line_number);
void fpop(stack_t **pila, unsigned int line_number);

char *_strdup(char *str);

#endif /* MONTY_H */
