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
	char str[1024];
	int i = 0;

	(void)line_number;
	while (current != NULL && current->n != 0 && current->n > 0
		&& current->n <= 127)
	{
		str[i] = current->n;
		i++;
		current = current->next;
	}
	str[i] = '\0';
	printf("%s\n", str);
}
