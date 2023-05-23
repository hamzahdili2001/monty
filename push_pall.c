#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, unsigned int line_number)
{
	int value = 0;
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newNode;

	*stack = newNode;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d", current->n);
		current = current->next;
	}
}

