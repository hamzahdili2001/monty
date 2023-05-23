#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * push - pushes to the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: Nothing.
*/
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *argument = data.argument;
	stack_t *newNode = malloc(sizeof(stack_t));

	if (argument == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!is_number(argument, &value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newNode;

	*stack = newNode;
}

/**
 * pall - prints all the values on the stack.
 * @stack: stack.
 * @line_number: line number
 * Return: Nothing.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

