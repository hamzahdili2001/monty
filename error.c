#include "monty.h"
#include <stdio.h>

/**
 * error - error hanndler to avoid more than 40 line.
 * @code: code for exit status.
 * @msg: string message.
 * @arg: argument for message (need some developement).
 * @type: type of the arg.
 * Return: exit status.
*/
int error(int code, char *msg, void *arg, char type)
{
	switch (type)
	{
	case 'd':
		fprintf(stderr, msg, *(int *)arg);
		break;
	case 's':
		fprintf(stderr, msg, (char *)arg);
		break;
	case 'u':
		fprintf(stderr, msg, *(unsigned int *)arg);
		break;
	case 'n':
		fprintf(stderr, msg, (void *)arg);
		break;
	}
	exit(code);
}
