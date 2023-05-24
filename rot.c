#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (current != NULL && current->next != NULL)
	{
		while (current->next != NULL)
			current = current->next;

		current->next = *stack;
		(*stack)->prev = current;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		current->next->next = NULL;
	}
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: stack.
 * @line_number: line_number.
 * Return: Nothing.
*/

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *last = NULL;

	(void)line_number;
	if (current == NULL || current->next == NULL)
		return;

	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}

	last->next = NULL;
	current->next = *stack;
	*stack = current;
}
