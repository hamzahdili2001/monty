#include "monty.h"
#include <stdio.h>
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

	(void)line_number;
	while (current != NULL && current->n != 0)
	{
		if (current->n < 0 || current->n > 128)
			break;

		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
