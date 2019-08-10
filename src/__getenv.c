#include "../libft/includes/libft.h"

char	*__getenv(char *name)
{
	size_t	len;
	int		i;

	if (name == NULL || (len = ft_strlen(name)) == 0)
		return (NULL);
	i = 0;
	while (__environ[i] != NULL)
	{
		if (__environ[i][len] == '=' &&
			ft_strncmp(__environ[i], name, len) == 0)
			return (__environ[i] + len + 1);
		i++;
	}
	return (NULL);
}
