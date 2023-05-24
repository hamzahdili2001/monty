#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
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

/**
 * sub -  subtracts the top element of the stack from
 *				the second top element of the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
*/
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fclose(data.bytecode_file);
		free(data.line);
		clean_s(*stack);
		error(EXIT_FAILURE, "L%u: can't sub, stack too short\n",
				(void *)&line_number, 'u');
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
