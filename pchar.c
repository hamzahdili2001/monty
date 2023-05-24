#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: stack.
 * @line_number: line number.
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int value = (*stack)->n;

	if (*stack == NULL || stack == NULL)
	{
		fclose(data.bytecode_file);
		free(data.line);
		clean_s(*stack);
		error(EXIT_FAILURE, "L%u: can't pchar, stack empty\n",
				(void *)&line_number, 'u');
	}
	if (value < 0 || value >= 128)
	{
		fclose(data.bytecode_file);
		free(data.line);
		clean_s(*stack);
		error(EXIT_FAILURE, "L%u: can't pchar, value out of range\n",
				(void *)&line_number, 'u');
	}

	printf("%c\n", value);
}
