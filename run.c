#include "monty.h"
#include <stdlib.h>
/**
 * run - runs the operations.
 * @line: line.
 * @stack: stack.
 * @line_number: line number.
 * @bytecode_file: bytecode file.
 * Return: result 0.
*/
int run(char *line, stack_t **stack, unsigned int line_number,
				FILE *bytecode_file)
{
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"sub", sub},
		{"div", divide}, {"nop", nop}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"stack", stack_c}, {"queue", queue_c},
		{NULL, NULL},
	};
	char *opcode;
	int result = 0, i = 0;

	opcode = strtok(line, " \t\n");
	data.argument = strtok(NULL, " \t\n");
	/* Check if the line is a comment */
	if (opcode && opcode[0] == '#')
		return (0);
	if (opcode != NULL)
	{
		while (opcodes[i].opcode != NULL)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(stack, line_number);
				break;
			}
			i++;
		}
	}
	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, opcode);
		fclose(bytecode_file);
		free(line);
		clean_s(*stack);
		exit(EXIT_FAILURE);
	}
	return (result);
}
