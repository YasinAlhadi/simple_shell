#include "main.h"

/**
 * main - Display a prompt and wait for the user to type a command
 * @ac: number of argument
 * @av: array of argument
 *
 * Return: 0
 */
int main(__attribute__((unused)) int ac, char **av)
{
	char *line = NULL;
	char **token = NULL;
	int loop = 1;

	pid_t child;
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		printf("YJ$ ");
		line = get_line();
		child = fork();
		if (_execute(child, line, token) == -1)
		{
			input_check(&line, av[0]);
			free(token);
			exit(EXIT_FAILURE);
		}
		loop++;
	}
	free(line);
	return (0);
}
