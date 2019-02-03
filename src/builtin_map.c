/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:36:54 by marvin            #+#    #+#             */
/*   Updated: 2019/02/02 22:33:42 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

struct s_builtin	g_src[] = {
	{"echo", 0},
	{"cd", 0},
	{"export", 0},
	{"env", 0},
};

struct s_builtin	g_map[MAP_SIZE] = {{0}};

unsigned long	sbdm(unsigned char *str)
{
	unsigned long	hash;
	int				c;

	hash = 0;
	while ((c = *str++))
		hash = c + (hash << 6) + (hash << 16) - hash;
	return (hash);
}

void			gen_map()
{
	unsigned long	hash;
	size_t			size;

	size = sizeof(g_src) / sizeof(struct s_builtin *);
	while (size-- > 0)
	{
		hash = sbdm((unsigned char*)g_src[size].name) / MAP_SIZE;
		while (g_map[hash].name != NULL)
			hash++;
		g_map[hash] = g_src[size];
	}
}
