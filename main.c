#include "monty.h"
/**
 * variable global
 */
global_t global;

/**
 * f_open - Function for opens file
 * @argv: List of past arguments
 * Return: File open
 */
FILE *f_open(char *argv)
{
	FILE *fp = NULL;

	fp = fopen(argv, "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	return (fp);
}

/**
 * main - Reads a text file and prints in to the POSIX stdout
 * @argc: Check past arguments
 * @argv: List of past arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	size_t size = 0;
	FILE *fp = NULL;
	stack_t *stack = NULL;
	unsigned int line = 0;
	char *str = NULL, *func = NULL;

	global.data = 0;
	global.size = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = f_open(argv[1]);
	on_exit(frees, &str);
	on_exit(free_stack, &stack);
	while (getline(&str, &size, fp) != -1)
	{
		func = strtok(str, DELIMITER);
		if (func != NULL && func[0] != '#')
		{
			get_func(func, &stack, line);
		}
		line++;

	}
	fclose(fp);
	exit(EXIT_SUCCESS);
}
