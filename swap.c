#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (*stack == NULL && (*stack)->next == NULL)
	{
		free(data.line);
		fclose(data.bytecode_file);
		clean_s(*stack);
		error(EXIT_FAILURE, "L%u: can't swap, stack too short\n",
				(void *)&line_number, 'u');
	}

	top = *stack;
	next = top->next;

	top->prev = next;
	top->next = next->next;

	if (next->next != NULL)
		next->next->prev = top;

	next->prev = NULL;
	next->next = top;

	*stack = next;
}
