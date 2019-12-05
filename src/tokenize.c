/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:35 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:55:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

static struct s_lst	*new_node(void *data)
{
	struct s_lst	*new;

	if (data == NULL)
		return (NULL);
	new = (struct s_lst *)malloc(sizeof(struct s_lst));
	new->data = data;
	new->size = 0;
	new->next = NULL;
	return (new);
}

static struct s_lst	*mklst(const char *str)
{
	struct s_lst	*head;
	struct s_lst	*curr;
	char			*token;

	token = ft_strtok((char *)str, " \n");
	curr = new_node(token);
	head = curr;
	while (token != NULL)
	{
		head->size += 1;
		token = ft_strtok(NULL, " \n");
		curr->next = new_node(token);
		curr = curr->next;
	}
	return (head);
}

static void			del(struct s_lst *head)
{
	struct s_lst	*next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

char				**tokenize(char *str)
{
	struct s_lst	*lst;
	struct s_lst	*curr;
	size_t			i;
	char			**tok;

	i = 0;
	if ((lst = mklst(str)) == NULL)
		return (NULL);
	curr = lst;
	tok = (char **)malloc((lst->size + 1) * sizeof(char *));
	while (curr != NULL)
	{
		tok[i++] = curr->data;
		curr = curr->next;
	}
	tok[i] = NULL;
	del(lst);
	return (tok);
}
