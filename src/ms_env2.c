/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 09:04:18 by tingo             #+#    #+#             */
/*   Updated: 2019/03/30 09:05:07 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

char		*__ms_builtin_getnenv(const char *name, size_t len)
{
	size_t i;

	i = 0;
	if (name == NULL || *name == '\0' || ft_strchr(name, '=') != NULL)
		return (NULL);
	len = ft_strlen(name);
	while(i < g_env_fill)
	{
		if (ft_strncmp(name, g_environ[i], len) == 0)
			return(g_environ[i] + len + 1);
		++i;
	}
	return (NULL);
}
