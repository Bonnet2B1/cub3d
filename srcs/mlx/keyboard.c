/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:34:53 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/12 17:35:01 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	keyboard(void *param)
{
	t_game_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->assets->minimap_player_img->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->assets->minimap_player_img->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->assets->minimap_player_img->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->assets->minimap_player_img->instances[0].x += 5;
}
