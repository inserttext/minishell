/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:59:48 by tingo             #+#    #+#             */
/*   Updated: 2019/01/15 00:06:58 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

static void			__ms_setenv_extend()
{
	char	**new;

	env_size += 10;
	new = (char **)ft_calloc(env_size, sizeof(char *));
	ft_memcpy(new, environ, env_fill);
	free(environ);
	environ = new;
}

static inline void	set(const char *name, const char *value, const size_t i)
{
	char	*t;

	t = environ[i];
	environ[i] = ft_strjoin(3, name, "=", value);
	free(t);
}


void				__ms_setenv_initenv()
{
	char* const	*env;
	char		**new;
	size_t		i;

	env = __environ;
	i = 0;
	while (*env)
		env++;
	env_size = env - __environ;
	new = (char **)malloc(sizeof(char *) * (env_size + 1));
	new[env_size] = 0;
	while (i < env_size)
	{
		new[i] = ft_strdup(__environ[i]);
		i++;
	}
	environ = new;
}

int					__ms_builtin_setenv(const char *name, const char *value,
										int overwrite)
{
	size_t	i;

	i = 0;
	if (name == NULL || *name == '\0' || ft_strchr(name, '=') != NULL)
		return (-1);
	while(i < env_fill)
	{
		if (!ft_strncmp(name, environ[i], ft_strlen(name)))
		{
			if (overwrite)
				set(name, value, i);
			break ;
		}
		++i;
	}
	if (env_fill == env_size)
		__ms_setenv_extend();
	if (environ[i] == NULL)
	{
		environ[i] = ft_strjoin(3, name, "=", value);
		++env_fill;
	}
	return (0);
}
