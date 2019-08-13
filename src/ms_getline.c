/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:31 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:54:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>

#define RSIZE 2048U

static char	*g_storep = 0;
static char	*g_store = 0;

static void	extend(char **m, size_t *size, size_t need, size_t filled)
{
	char	*new;

	if (need < *size * 2)
		need = *size * 2;
	new = (char *)malloc(need * sizeof(char));
	ft_memcpy(new, *m, filled);
	*size = need;
	free(*m);
	*m = new;
}

static void	storefn(char *buf)
{
	size_t len;

	len = ft_strlen(buf);
	g_storep = (char *)malloc(sizeof(char) * (len + 1));
	ft_memcpy(g_storep, buf, len);
	g_storep[len] = '\0';
	g_store = g_storep;
}

static int	recall(char **line, size_t *size, size_t *fill)
{
	char	*c;
	size_t	need;

	if ((c = ft_strchr(g_store, '\n')) != NULL)
		need = c - g_store + 1;
	else
		need = ft_strlen(g_store);
	if (need > *size)
		extend(line, size, need, 0);
	ft_memcpy(*line, g_store, need);
	if (*(g_store += need) == '\0')
	{
		free(g_storep);
		g_store = NULL;
	}
	*fill = need;
	(*line)[need] = '\0';
	return (!!c);
}

static void	aux(char **c, size_t *need, char *buf)
{
	if ((*c = ft_strchr(buf, '\n')) != NULL)
	{
		if (*need > (uintptr_t)*c - (uintptr_t)buf + 1U)
			storefn(*c + 1);
		*need = *c - buf + 2;
	}
	else if (*need < RSIZE)
		exit(0);
}

size_t		ms_getline(char **line)
{
	char	*c;
	char	buf[RSIZE + 1];
	size_t	size;
	size_t	fill;
	size_t	need;

	fill = 0;
	size = RSIZE + 1;
	*line = (char *)malloc(size * sizeof(char));
	if (g_store != NULL)
		if (recall(line, &size, &fill) != 0)
			return (fill);
	while ((need = read(STDIN_FILENO, buf, RSIZE)) > 0)
	{
		buf[need] = '\0';
		aux(&c, &need, buf);
		if (need >= size)
			extend(line, &size, need, fill);
		ft_memcpy(*line, buf, need);
		fill += need - 1;
		if (c != NULL)
			break ;
	}
	(*line)[fill] = '\0';
	return (fill);
}
