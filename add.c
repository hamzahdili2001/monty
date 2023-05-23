#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fclose(data.bytecode_file);
		free(data.line);
		clean_s(*stack);
		error(EXIT_FAILURE, "L%u: can't add, stack too short\n",
				(void *)&line_number, 'u');
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
