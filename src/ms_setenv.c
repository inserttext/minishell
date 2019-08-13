/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:33 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:55:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

static void	new_entry(char *name, const char *value)
{
	char **new;

	g_env_size += 1;
	new = (char **)ft_calloc(g_env_size + 1, sizeof(char *));
	ft_memcpy(new, g_environ, g_env_size * sizeof(char *));
	new[g_env_size - 1] = ft_strjoin(3, name, "=", value);
	free(g_environ);
	g_environ = new;
}

static void	replace(char **loc, char *name, const char *value)
{
	char *tmp;

	tmp = *loc;
	*loc = ft_strjoin(3, name, "=", value);
	free(tmp);
}

void		ms_setenv(char *name, const char *value, int overwrite)
{
	size_t	i;
	size_t	len;

	if (name == NULL || (len = ft_strlen(name)) == 0)
		return ;
	i = 0;
	while (g_environ[i] != NULL)
	{
		if (g_environ[i][len] == '=' &&
			ft_strncmp(g_environ[i], name, len) == 0)
		{
			if (overwrite)
				replace(g_environ + i, name, value);
			return ;
		}
		i++;
	}
	new_entry(name, value);
}
