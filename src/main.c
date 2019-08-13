#include "../includes/minishell.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>

size_t	g_env_size;
char	**g_environ;

static size_t	__get_env_size()
{
	size_t len;

	len = 0;
	while (__environ[len] != NULL)
		len++;
	return (len);
}

static void		env_cpy()
{
	size_t i;

	i = 0;
	g_environ = (char **)ft_calloc(g_env_size + 1, sizeof(char *));
	while (__environ[i] != NULL)
	{
		g_environ[i] = ft_strdup(__environ[i]);
		i++;
	}
}

static void		del_env()
{
	size_t i;

	i = 0;
	while (g_environ[i] != NULL)
	{
		free(g_environ[i]);
		i++;
	}
	free(g_environ);
}

int				main(void)
{
	g_env_size = __get_env_size();
	env_cpy();
	ms_loop();
	del_env();
	return(0);
}
