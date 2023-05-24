#include "monty.h"
/**
 * pop - Removes the top element of the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		error(EXIT_FAILURE, "L%u: can't pop an empty stack\n",
				(void *)&line_number, 'u');
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
