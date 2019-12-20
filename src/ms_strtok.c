/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:35 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:55:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char		*brack(char *s, char del, char **save, ssize_t *len)
{
	char *end;
	char d[2];

	d[0] = del;
	d[1] = '\0';
	end = s;
	while (1)
	{
		end += ft_strcspn(end, d);
		if (*end == '\0')
			write(1, "Extend line", 1);
		else if (end[-1] == '\\')
			continue;
		else
			break;
	}
	*end = '\0';
	*save = end + 1;
	return (s);
}

char		*brack2(char *in, char **save, ssize_t *len)
{

}

char		*ms_strtok(char **s, ssize_t *len)
{
	static char	**hold;
	static char	*olds;

	if (*s != NULL)
	{
		hold = s;
		olds = *s;
	}
	olds += ft_strspn(olds, " ");
	if (*olds == '\0')
		return (NULL);
	if (*olds == '"' || *olds == '\'')
		return (brack(olds + 1, *olds, &olds, len));
	return (brack2(olds, &olds, len));
}
