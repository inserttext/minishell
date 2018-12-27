/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 03:48:03 by tingo             #+#    #+#             */
/*   Updated: 2018/12/20 19:25:09 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

int	main()
{
	char	*line;
	size_t	len;
	size_t	read;

	line = 0;
	len = 0;
	while (1)
	{
		write(1, "$> ", 3);
		read = ms_getline(&line, &len);
		ft_printf("%lu\n", read);
	}
	free(line);
	return (0);
}
