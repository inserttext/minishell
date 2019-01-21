/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 06:59:45 by tingo             #+#    #+#             */
/*   Updated: 2019/01/19 19:15:49 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>

extern char		**environ;
extern size_t	env_size;
extern size_t	env_fill;

size_t	ms_getline(char **line);
void	ms_exit(int n);

void	ms_loop();
void	__ms_setenv_initenv();
#endif
