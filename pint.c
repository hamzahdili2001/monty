#include "monty.h"
#include <stdlib.h>

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		free(data.line);
		fclose(data.bytecode_file);
		clean_s(*stack);
		error(EXIT_FAILURE, "L%u: can't pint, stack empty\n", (void *)&line_number, 'u');
	}
		printf("%d\n", (*stack)->n);
}
