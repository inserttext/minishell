#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

static void	delete(char **pos)
{
	char	**old;
	char	**a;
	char	**z;
	size_t	i;

	i = 0;
	old = g_environ;
	a = g_environ;
	z = pos + 1;
	g_env_size -= 1;
	free(*pos);
	*pos = NULL;
	g_environ = (char **)malloc((g_env_size + 1) * sizeof(char *));
	while (*a != NULL)
		g_environ[i++] = *a++;
	while (*z != NULL)
		g_environ[i++] = *z++;
	g_environ[i] = NULL;
	free(old);
}

void		__unsetenv(char *name)
{
	size_t	i;
	size_t	len;

	if (name == NULL || (len = ft_strlen(name)) == 0)
		return;
	i = 0;
	while (g_environ[i] != NULL)
	{
		if (g_environ[i][len] == '=' &&
			ft_strncmp(g_environ[i], name, len) == 0)
		{
			delete(g_environ + i);
			return;
		}
		i++;
	}
}
