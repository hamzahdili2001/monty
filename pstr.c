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
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current && current->n > 0 && current->n < 128)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
