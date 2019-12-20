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

char		*brack(char *in, char d, char **save, ssize_t *len)
{

}

char		*ms_strtok(char **s, ssize_t *len)
{
	static char	**olds;
	char		*in;

	if (*s != NULL)
		olds = s;
	in = *olds;
	in += ft_strspn(in, " \t");
	if (*in == '\0')
		return (NULL);
	if (*in == '"' || *in == '\'')
		return (brack(in + 1, *in, olds, len));
	return (brack(in + 1, *in, olds, len));
}
