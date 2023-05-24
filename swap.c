#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int length = 0, temp;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		error(EXIT_FAILURE, "L%u: can't swap, stack too short\n",
				(void *)&line_number, 'u');
	}

	current = *stack;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
