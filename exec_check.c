

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
