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

	while(1)
	{
		write(STDOUT_FILENO, "$>", 2);
		__getline(&line);
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
		for (int i = 0; tok[i]; i++)
			printf("%s\n", tok[i]);
		delete(tok);
		free(line);
	}
}
