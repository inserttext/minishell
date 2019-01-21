/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 03:48:03 by tingo             #+#    #+#             */
/*   Updated: 2019/01/18 21:56:25 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

size_t	env_size = 0;
size_t	env_fill = 0;
char	**environ = 0;

int	main()
{
	__ms_setenv_initenv();
	ms_loop();
	return (0);
}
