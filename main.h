#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;



char *get_line(void);
int _execute(pid_t child, char *line, char **token);
void input_check(char **line, char *name);
char **split_line(char *line);
char *_getenv(char *name);
char *find_path(char *arr_path, char *cmd);
int _path(char **av);

#endif /* MAIN */
