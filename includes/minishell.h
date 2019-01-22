/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 06:59:45 by tingo             #+#    #+#             */
/*   Updated: 2019/01/21 19:36:09 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>

extern char		**environ;
extern size_t	env_size;
extern size_t	env_fill;

size_t	ms_getline(char **line);

char	**ms_tokenize(char **line, size_t len);

void	ms_loop();
void	__ms_setenv_initenv();
#endif
