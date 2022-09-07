
		else
		{
			free(line);
			perror("Error read line: getline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

/**
 * split_line - divide the string into tokens
 * @line: input from getline
 *
 * Return: tokens
 */
char **split_line(char *line)
{
	char **tokens = NULL;
	char *token = strdup(line);
	int i = 0, j = 0;
	char *tmp = NULL;

	tmp = line;
	tmp = strtok(tmp, " \n\t");
	while (tmp != NULL)
	{
		j++;
		tmp = strtok(NULL, " \n\t");
	}
	tokens = (char **) malloc((j * sizeof(char *) + 1));
	token = strtok(token, " \n\t");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, " \n\t");
	}
	tokens[j + 1] = '\0';
	free(token);
	return (tokens);
}
