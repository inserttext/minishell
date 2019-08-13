/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:02 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:40:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <unistd.h>

int	builtin_echo(char **tok)
{
	tok++;
	while (*tok != NULL)
	{
		write(STDOUT_FILENO, *tok, ft_strlen(*tok));
		tok++;
		if (*tok != NULL)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
