#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>

static inline
void	preload(char **line, char *hold)
{
	*line = (char *)ft_calloc(ft_strlen(hold) + 1, sizeof(char));
	ft_strcpy(*line, hold);
	ft_bzero(hold, 256);
}

void	__getline(char **line)
{
	static char	hold[256] = {0};
	char		*buf;
	char		*tmp;
	char		*nl;

	if (hold[0] != '\0')
		preload(line, hold);
	*line = NULL;
	buf = (char *)ft_calloc(256, sizeof(char));
	while (read(STDIN_FILENO, buf, 255) > 0)
	{
		if ((nl = ft_strchr(buf, '\n')) != NULL)
		{
			*nl = '\0';
			ft_strcpy(hold, nl + 1);
		}
		tmp = *line;
		*line = ft_strjoin(2, *line, buf);
		if (tmp != NULL)
			free(tmp);
		if (nl != NULL)
			return;
		ft_bzero(buf, 256);
	}
}
