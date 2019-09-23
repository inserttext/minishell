/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:56:40 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:57:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>

struct			s_func
{
	char	*name;
	int		(*f)(char**);
};

struct			s_lst
{
	void			*data;
	size_t			size;
	struct s_lst	*next;
};

extern size_t	g_env_size;
extern char		**g_environ;
extern char		*g_pid;

char			*ms_getenv(char *name);
void			ms_setenv(char *name, const char *value, int overwrite);
void			ms_unsetenv(char *name);

void			ms_loop();
size_t			ms_getline(char **line);
char			**tokenize(char *str);
void			substitute(char **tok);
int				launcher(char **tok);

int				builtin_cd(char **tok);
int				builtin_exit(char **tok);
int				builtin_echo(char **tok);
int				builtin_env(char **tok);
int				builtin_export(char **tok);
int				builtin_unset(char **tok);

#endif
