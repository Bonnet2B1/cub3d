/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_with_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:47:11 by momox             #+#    #+#             */
/*   Updated: 2024/02/04 19:47:15 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_with_spaces(t_game *data, t_map *gps)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = x_malloc(&data->x_chain, sizeof(char *) * (gps->height + 1));
	i = -1;
	while (++i < gps->height)
	{
		new_map[i] = x_malloc(&data->x_chain, sizeof(char) * (gps->width + 1));
		j = -1;
		while (gps->map[i][++j])
			new_map[i][j] = gps->map[i][j];
		while (j < gps->width)
			new_map[i][j++] = ' ';
	}
	gps->map = new_map;
}
