#include "main.h"

/**
 * _getenv - gets all PATH line
 * @name: environment variable to find
 *
 * Return: Array of PATH line
 */
char *_getenv(char *name)
{
	int i = 0;
	char *get;

	while (environ[i] != NULL)
	{
		get = strtok(environ[i], "=");
		if (strcmp(get, name) == 0)
		{
			get = strtok(NULL, "\0");
			break;
		}
		i++;
	}
	return (get);
}

/**
 * find_path - function that locate a command in PATH envir
 * @arr_path: array of path
 * @cmd: command to find
 *
 * Return:array of path of comand
 */
char *find_path(char *arr_path, char *cmd)
{
	int len1, len2, i = 0, b = 0;
	char *new_p;

	len1 = strlen(arr_path);
	len2 = strlen(cmd);
	new_p = malloc((len1 + len2) + 1);
	while (arr_path[i] != '\0')
	{
		new_p[i] = arr_path[i];
		i++;
	}
	new_p[i] = '/';
	i++;
	while (cmd[b] != '\0')
	{
		new_p[i] = cmd[b];
		i++;
		b++;
	}
	new_p[i + 1] = '\0';
	return (new_p);
}
/**
 * _path - function to find path of shell
 * @argv: input
 *
 * Return: 0 on success, -1 on failure
 */
int _path(char **argv)
{
	char *path = NULL;
	char *str = NULL;
	struct stat st;
	unsigned int i;

	path = _getenv("PATH");
	path = strtok(path, ":");
	i = 0;
	while (path != NULL)
	{
		str = find_path(path, argv[0]);
		if (stat(str, &st) == 0)
		{
			argv[0] = strdup(str);
			break;
		}
		path = strtok(NULL, ":");
		i++;
	}
	free(str);
	if (execve(argv[0], argv, NULL) == -1)
		return (-1);
	return (0);
}
