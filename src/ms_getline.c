/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 06:58:41 by tingo             #+#    #+#             */
/*   Updated: 2018/12/20 00:01:20 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

#define RSIZE 128

static void		extend(char **line, size_t *n, size_t need)
{
	char *tmp;

	if (need < 2 * *n)
		need = 2 * *n;
	if (!(tmp = (char *)malloc(sizeof(char) * need)))
		exit(1);
	ft_memcpy(tmp, *line, *n);
	free(*line);
	*line = tmp;
	*n = need;
}

static void		prep(char **line, size_t *n)
{
	if (*line == 0 && *n == 0)
	{
		*n = RSIZE + 1;
		if (!(*line = (char *)malloc(sizeof(char) * *n)))
			exit(1);
	}
}

ssize_t			ms_getline(char **line, size_t *n)
{
	ssize_t		curr;
	ssize_t		len;
	size_t		need;
	char		*c;
	char		buf[RSIZE + 1];

	prep(line, n);
	curr = 0;
	while ((len = read(STDIN_FILENO, buf, RSIZE)) > 0)
	{
		c = ft_memchr(buf, '\n', len);
		if (c)
			len = c - buf + 1;
		need = curr + len + 1;
		if (need > *n)
			extend(line, n, need);
		ft_memcpy(*line + curr, buf, len);
		curr += len;
		if (c)
			break;
	}
	if (len == 0)
		ms_exit(0);
	(*line)[curr] = '\0';
	return (curr);
}
