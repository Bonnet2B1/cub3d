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
	if (player->front->type == 'C' && player->front->len <= 3)
	{
		check_beyond_the_wall(data, data->gps, player->front);
		data->gps->map[player->front->map_y][player->front->map_x] = 'O';
	}
}
