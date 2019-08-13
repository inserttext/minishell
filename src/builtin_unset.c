/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:28 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:40:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

#define ENVC "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"

int	builtin_unset(char **tok)
{
	char *name;

	if (tok[1] == NULL)
		return (0);
	name = tok[1];
	if (ft_strspn(name, ENVC) < ft_strlen(name))
	{
		ft_printf("unset: not valid in this context: %s\n", name);
		return (0);
	}
	ms_unsetenv(name);
	return (0);
}
