#include "monty.h"
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
	unsigned int line = 1;
	stack_t *stack = NULL;
	char *str = NULL, *func = NULL;

	global.data = 0;
	global.size = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = f_open(argv[1]);
	while (getline(&str, &size, fp) != -1)
	{
		func = strtok(str, " \t\n\r");
		if (func != NULL && func[0] != '#')
		{
			get_func(func, &stack, line);
		}
		line++;
	}
	free(str);
	free_stack(stack);
	fclose(fp);
	return (0);
}
