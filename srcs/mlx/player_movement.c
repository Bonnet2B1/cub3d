/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:27:01 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/17 15:27:14 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_movement(t_game_data *data, int delta_x, int delta_y)
{
	data->assets->minimap_player_img->instances[0].y += delta_y;
	data->assets->minimap_player_img->instances[0].x += delta_x;
}
