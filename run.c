#include "monty.h"
#include <stdlib.h>

int run(char *line, stack_t **stack, unsigned int line_number, FILE *bytecode_file)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL},
	};
	char *opcode;
	int result = 0, i = 0;

	opcode = strtok(line, " \t\n");
	data.argument = strtok(NULL, " \t\n");

	if (opcode != NULL)
	{
		while(opcodes[i].opcode != NULL)
		{
			if(strcmp(opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(stack, line_number);
				break;
			}
			i++;
		}
	}

	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		fclose(bytecode_file);
		free(line);
		/* clean_s(*stack) */
		exit(EXIT_FAILURE);
	}
	return (result);
}
