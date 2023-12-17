/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:34:53 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/17 17:26:12 by edelarbr         ###   ########.fr       */
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
		player_movement(data, 0, -1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		player_movement(data, 0, +1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		player_movement(data, -1, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		player_movement(data, +1, 0);
}
