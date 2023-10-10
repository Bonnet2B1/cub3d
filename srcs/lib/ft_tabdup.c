/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:37:20 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/10 22:45:52 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_tabdup(t_list **x_chain, char **tab)
{
	int		i;
	char	**new_tab;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		i++;
	new_tab = x_malloc(x_chain, sizeof(char *) * (i + 1));
	if (!new_tab)
		return (perror("Malloc"), NULL);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = ft_strdup(x_chain, tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}
