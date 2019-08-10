#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

char	*__getenv(char *name)
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
