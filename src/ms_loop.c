#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

void	delete(char **mem)
{
	size_t i;

	i = 0;
	while (mem[i] != NULL)
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}

void	ms_loop()
{
	char	*line;
	char	**tok;
	int		loop;

	loop = 1;
	while(loop >= 0)
	{
		write(STDOUT_FILENO, "$>", 2);
		if (__getline(&line) == 0)
			return;
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		tok = tokenize(line);
		if (tok == NULL)
		{
			free(line);
			continue;
		}
		tok = substitute(tok);
		loop = launcher(tok);
		delete(tok);
		free(line);
	}
}
