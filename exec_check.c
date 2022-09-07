#include "main.h"
/**
 * _execute - function that execute and check the prosecc
 * @child: child id
 * @line: buffer of line
 * @token: pointer to array to tokenize lines
 *
 * Return: 0
 */
int _execute(pid_t child, char *line, char **token)
{
	int errors = 1;

	if (child == -1)
	{
		perror("faild to cereate prosecc");
		return (1);
	}
	if (child == 0)
	{
		token = split_line(line);
		if (_path(token) == -1)
		{
			return (-1);
		}
		else
			errors++;
	}
	else
	{
		wait(NULL);
	}
	free(token);
	return (0);
}

/**
 * input_check - function that prints error message
 * @line: buffer of line
 * @name: name of program
 *
 * Return: void
 */
void input_check(char **line, char *name)
{
	write(2, name, strlen(name));
	write(2, ": ", 2);
	write(2, *line, strlen(*line));
	write(2, ": not found\n", 12);
}
