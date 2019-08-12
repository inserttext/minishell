#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

void	ms_loop()
{
	char	*line;
	char	**tok;

	while(1)
	{
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
		for (int i = 0; tok[i] != NULL; i++)
			printf("%s\n", tok[i]);
		free(line);
		free(tok);
	}
}
