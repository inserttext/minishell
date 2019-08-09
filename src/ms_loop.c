#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

void	ms_loop()
{
	char	*line;

	while(1)
	{
		__getline(&line);
		ft_printf("%s\n", line);
	}
}
