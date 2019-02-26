/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:59:48 by tingo             #+#    #+#             */
/*   Updated: 2019/02/22 02:48:49 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

void		__ms_setenv_extend()
{
	char	**new;

	g_env_size += 10;
	new = (char **)ft_calloc(g_env_size, sizeof(char *));
	ft_memcpy(new, g_environ, g_env_fill);
	free(g_environ);
	g_environ = new;
}

void	set(const char *name, const char *value, const size_t i)
{
	char	*t;

	t = g_environ[i];
	g_environ[i] = ft_strjoin(3, name, "=", value);
	free(t);
}


void		__ms_setenv_initenv()
{
	char* const	*env;
	char		**new;
	size_t		i;

	env = __environ;
	i = 0;
	while (*env)
		env++;
	g_env_size = env - __environ;
	new = (char **)malloc(sizeof(char *) * (g_env_size + 1));
	new[g_env_size] = 0;
	while (i < g_env_size)
	{
		new[i] = ft_strdup(__environ[i]);
		i++;
	}
	g_environ = new;
}

int			__ms_builtin_setenv(const char *name, const char *value,
								int overwrite)
{
	size_t	i;

	i = 0;
	if (name == NULL || *name == '\0' || ft_strchr(name, '=') != NULL)
		return (-1);
	while(i < g_env_fill)
	{
		if (!ft_strncmp(name, g_environ[i], ft_strlen(name)))
		{
			if (overwrite)
				set(name, value, i);
			break ;
		}
		++i;
	}
	if (g_env_fill == g_env_size)
		__ms_setenv_extend();
	if (g_environ[i] == NULL)
	{
		g_environ[i] = ft_strjoin(3, name, "=", value);
		++g_env_fill;
	}
	return (0);
}

char		*__ms_builtin_getenv(const char *name)
{
	size_t i;
	size_t len;

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
