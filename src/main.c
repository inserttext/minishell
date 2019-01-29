/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 03:48:03 by tingo             #+#    #+#             */
/*   Updated: 2019/01/27 17:08:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

size_t	g_env_size = 0;
size_t	g_env_fill = 0;
char	**g_environ = 0;

int	main()
{
	__ms_setenv_initenv();
	ms_loop();
	return (0);
}
