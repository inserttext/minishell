#include "../libft/includes/libft.h"
#include <unistd.h>

int	__echo(char **tok)
{
	tok++;
	while (*tok != NULL)
	{
		write(STDOUT_FILENO, *tok, ft_strlen(*tok));
		tok++;
		if (*tok != NULL)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
