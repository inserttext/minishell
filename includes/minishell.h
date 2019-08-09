#ifndef MINISHELL_H
# define MINISHELL_H

#include "unistd.h"

extern size_t	__env_size;

char			*__getenv(char *name);
void			__setenv(char *name, const char *value, int overwrite);

void			ms_loop();
void			__getline(char **line);

#endif
