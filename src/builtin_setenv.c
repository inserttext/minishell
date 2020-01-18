/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:27 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:40:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

#define ENVC "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"

int	builtin_setenv(char **tok)
{
	char *name;
	char *value;

	if (tok[1] == NULL || (value = ft_strchr(tok[1], '=')) == NULL)
		return (0);
	value += ft_strspn(value, "=");
	name = ft_strtok(tok[1], "=");
	if (ft_strspn(name, ENVC) < ft_strlen(name))
	{
		ft_printf("export: not valid in this context: %s\n", name);
		return (0);
	}
	ms_setenv(name, value, 1);
	return (0);
}
