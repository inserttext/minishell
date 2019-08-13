#ifndef MINISHELL_H
# define MINISHELL_H

#include "unistd.h"

extern size_t	g_env_size;
extern char		**g_environ;

char			*__getenv(char *name);
void			__setenv(char *name, const char *value, int overwrite);

void			ms_loop();
void			__getline(char **line);
char			**tokenize(char *str);
char			**substitute(char **tok);
int				launcher(char **tok);

#endif
