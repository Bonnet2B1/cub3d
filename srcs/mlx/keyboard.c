/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:34:53 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/15 17:34:35 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_movement(t_game_data *data, int delta_x, int delta_y)
{
	data->assets->minimap_player_img->instances[0].y += delta_y;
	data->assets->minimap_player_img->instances[0].x += delta_x;
}

void	keyboard(void *param)
{
	t_game_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		player_movement(data, 0, -5);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		player_movement(data, 0, +5);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		player_movement(data, -5, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		player_movement(data, +5, 0);
}
