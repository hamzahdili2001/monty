#include "monty.h"

int run(char *line, stack_t **stack, unsigned int line_number, FILE *bytecode_file)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};
	char *opcode, *argument;
	int result = 0, i = 0;

	opcode = strtok(line, " \t\n");
	argument = strtok(NULL, " \t\n");

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

	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	}

	return (result);
}

