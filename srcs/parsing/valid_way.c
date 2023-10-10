/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:41:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/10 21:39:54 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_player_x(t_game_data *data)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (data->map[++y])
	{
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'W' || data->map[y][x] == 'E')
				return (x);
		}
		x = -1;
	}
	return (0);
}

int	find_player_y(t_game_data *data)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (data->map[++y])
	{
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'W' || data->map[y][x] == 'E')
				return (y);
		}
		x = -1;
	}
	return (0);
}

int	valid_way(t_map *temp, int x, int y)
{
	if (temp->map[y][x] == '1')
		return (0);
	if (temp->map[y][x] == ' ' || temp->map[y][x] == '\0')
		return (temp->hole, 1);

	temp->map[y][x] = '1';
	valid_way(temp, (x + 1), y);
	valid_way(temp, (x - 1), y);
	valid_way(temp, x, (y + 1));
	valid_way(temp, x, (y - 1));
	if (!temp->collectible)
		return (1);
	return (0);
}
