#include "../libft/includes/libft.h"

char	*__getenv(char *name)
{
	size_t	len;
	int		i;

	i = 0;
	if (name == NULL || (len = ft_strlen(name)) == 0)
		return (NULL);
	if (name[len - 1] == '=')
		len -= 1;
	while (__environ[i][len] == '=' && ft_strncmp(__environ[i], name, len) != 0)
		i++;
	return (__environ[i]);
}
