#ifndef MINISHELL_H
# define MINISHELL_H

#include "unistd.h"

extern size_t	g_env_size;
extern char		**g_environ;
extern char		*g_pid;

char			*__getenv(char *name);
void			__setenv(char *name, const char *value, int overwrite);
void			__unsetenv(char *name);

void			ms_loop();
size_t			__getline(char **line);
char			**tokenize(char *str);
void			substitute(char **tok);
int				launcher(char **tok);

int				__cd(char **tok);
int				__exit(char **tok);
int				__echo(char **tok);
int				__env(char **tok);
int				__export(char **tok);
int				__unset(char **tok);

#endif
