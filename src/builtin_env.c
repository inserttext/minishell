/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:17 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:40:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

int	builtin_env(char **tok)
{
	const char **env;

	(void)tok;
	env = (const char **)g_environ;
	while (*env != NULL)
	{
		ft_printf("%s\n", *env);
		env++;
	}
	return (0);
}
