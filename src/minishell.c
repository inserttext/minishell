/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 07:02:32 by tingo             #+#    #+#             */
/*   Updated: 2019/01/21 19:26:22 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

void	ms_loop()
{
	char	*line;
	char	**token;
	size_t	len;

	while (1)
	{
		write(1, "$> ", 3);
		len = ms_getline(&line);
		if (line[len - 1] != '\n')
			exit (0);
		token = ms_tokenize(&line, len);
		for (int i = 0; token[i] != NULL; i++) {
			printf("%s\n", token[i]);
		}

		free(line);
		free(token);
	}
}
