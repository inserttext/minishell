/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:59:48 by tingo             #+#    #+#             */
/*   Updated: 2018/12/25 01:52:48 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	**environ = 0;
size_t	env_size = 0;

static int		__ms_setenv_extend(size_t *n)
{
	char	**new;

	*n += 10;
	new = (char **)ft_calloc(*n, sizeof(char *));
}

static char		**__ms_setenv_initenv()
{

}

static size_t	__ms_setenv_getsize()
{
	char * const *env;

	env = __environ;
	while (*env)
		env++;
	return (env - __environ);
}

int				__ms_builtin_setenv(const char *name, const char *value,
									int overwrite)
{
	char	***env;

	env = &environ;
	if (env_size == 0 && **environ)
		env_size = __ms_setenv_getsize();
	if (*env == 0)
		*env = __ms_setenv_initenv();
	if (name == 0 || *name == '\0' || ft_strchr(name, '=') != NULL)
		return (-1);
	while(**env)
	{
		if (!ft_strncmp(name, **env, ft_strlen(name)))
			**env = ft_strjoin(3, name, "=", value);
		++*env;
	}
	return (0);
}
