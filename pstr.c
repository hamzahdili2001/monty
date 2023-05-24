#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack,
 *				followed by a new line.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int value;

	(void)line_number;
	while (current != NULL && current->n != 0 && current->n > 0
		&& current->n <= 127)
	{
		value = current->n;
		printf("%c", value);
		current = current->next;
	}
	printf("\n");
}
