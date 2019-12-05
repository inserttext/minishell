/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:31 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:40:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*ms_getenv(char *name)
{
	size_t	len;
	int		i;

	if (name == NULL || (len = ft_strlen(name)) == 0)
		return (NULL);
	i = 0;
	while (g_environ[i] != NULL)
	{
		if (g_environ[i][len] == '=' &&
			ft_strncmp(g_environ[i], name, len) == 0)
			return (g_environ[i] + len + 1);
		i++;
	}
	return (NULL);
}
