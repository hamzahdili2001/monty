#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
*/

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL && (*stack)->next == NULL)
	{
		free(data.line);
		fclose(data.bytecode_file);
		clean_s(*stack);
		error(EXIT_FAILURE, "L%u: can't swap, stack too short\n",
				(void *)&line_number, 'u');
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
