/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 06:59:45 by tingo             #+#    #+#             */
/*   Updated: 2019/02/02 23:08:00 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>

extern char		**g_environ;
extern size_t	g_env_size;
extern size_t	g_env_fill;

size_t	ms_getline(char **line);

char	**ms_tokenize(char **line, size_t len);

void	ms_loop();
void	__ms_setenv_initenv();

/*
** for builtin dispatch
*/

#define MAP_SIZE 128

struct s_builtin
{
	char	*name;
	int		(*f)(char**);
};

extern struct s_builtin g_src[];
extern struct s_builtin	g_map[MAP_SIZE];

void	gen_map();
unsigned long	sbdm(unsigned char *str);

#endif
