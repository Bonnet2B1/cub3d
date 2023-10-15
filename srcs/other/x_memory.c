/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_memory.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:28:17 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/12 18:43:24 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_list	*x_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (perror("malloc"), NULL);
	if (list)
	{
		list->content = content;
		list->next = NULL;
		list->prev = NULL;
	}
	return (list);
}

void	*x_malloc(t_list **lst, size_t size)
{
	t_list			*new;
	unsigned char	*ret;
	size_t			i;

	ret = malloc(size);
	if (!ret)
		return (perror("malloc"), NULL);
	i = 0;
	while (i < size)
		ret[i++] = 0;
	new = x_lstnew(ret);
	if (!new)
		return (NULL);
	ft_lstadd_back(lst, new);
	return (ret);
}

void	x_free(t_list **x_chain)
{
	t_list	*temp;

	while (*x_chain)
	{
		temp = *x_chain;
		*x_chain = (*x_chain)->next;
		free(temp->content);
		free(temp);
	}
	free(*x_chain);
}
