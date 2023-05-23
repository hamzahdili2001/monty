#include "monty.h"
#include <stdlib.h>

int main(int argc, const char *const argv[])
{
	const char *filename;
	FILE *bytecode_file;
	char *line = NULL;
	size_t size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	bytecode_file = fopen(filename, "r");
	
	if (!bytecode_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &size, bytecode_file) != -1)
	{
		line_number++;
		if(run(line, &stack, line_number, bytecode_file) != 0)
		{
			fprintf(stderr, "Error: Failed to execute line %u\n", line_number);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = NULL;
		size = 0;
	}

	if(ferror(bytecode_file))
	{
		fprintf(stderr, "Error: Failed to read file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	//clean_s(stack);
	fclose(bytecode_file);

	return (EXIT_SUCCESS);
}
