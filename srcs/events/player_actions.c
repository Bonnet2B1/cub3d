/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:17:53 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/31 17:30:05 by edelarbr         ###   ########.fr       */
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

	player = data->player;
	player->front->angle = player->angle;
	deep_ray_cpy(player->front);
	player->front->len = get_len(data, player->front);
	if (player->front->type == '3' && player->front->len <= 3)
	{
		data->gps->map[player->front->map_y][player->front->map_x] = '4';
		usleep(70000);
	}
	else if (player->front->type == '4' && player->front->len <= 3)
	{
		data->gps->map[player->front->map_y][player->front->map_x] = '3';
		usleep(70000);
	}
}
