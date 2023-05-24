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
		error(EXIT_FAILURE, "L%u: can't sub, stack too short\n",
				(void *)&line_number, 'u');
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * divide -  divides the second top element
 *					of the stack by the top element of the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
*/
void divide(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		error(EXIT_FAILURE, "L%u: can't div, stack too short\n",
				(void *)&line_number, 'u');
	}

	if ((*stack)->n == 0)
	{
		error(EXIT_FAILURE, "L%u: division by zero\n", (void *)&line_number, 'u');
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the
 *				stack with the top element of the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		error(EXIT_FAILURE, "L%u: can't mul, stack too short\n",
				(void *)&line_number, 'u');
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - computes the rest of the division of the second top element
 *			of the stack by the top element of the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		error(EXIT_FAILURE, "L%u: can't mod, stack too short\n",
				(void *)&line_number, 'u');
	}

	if ((*stack)->n == 0)
		error(EXIT_FAILURE, "L%u: division by zero\n", (void *)&line_number, 'u');

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

