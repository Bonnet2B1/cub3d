/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:17:53 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/05 19:48:23 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	open_door(t_game *data)
{
	t_player	*player;

	player = data->player;
	player->front->angle = player->angle;
	deep_ray_cpy(player->front);
	player->front->len = get_len(data, player->front);
	if (player->front->type == 'D' && player->front->len <= 3)
		data->gps->map[player->front->map_y][player->front->map_x] = '0';
}

void	mod_wall(t_game *data)
{
	t_player	*player;
	int			i;

	i = -1;
	player = data->player;
	player->front->angle = player->angle;
	deep_ray_cpy(player->front);
	player->front->len = get_len(data, player->front);
	if (player->front->type == '3' && player->front->len <= 3)
	{
		data->gps->map[player->front->map_y][player->front->map_x] = '4';
		while (++i < 5000000)
			printf("");
	}
	else if (player->front->type == '4' && player->front->len <= 3)
	{
		data->gps->map[player->front->map_y][player->front->map_x] = '3';
		while (++i < 5000000)
			printf("");
	}
}
