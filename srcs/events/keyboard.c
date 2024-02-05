/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:34:53 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/04 20:09:05 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	keyboard_two(t_game *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_E)
		|| (data->mouse == 1 && mlx_is_mouse_down(data->mlx,
				MLX_MOUSE_BUTTON_LEFT)))
	{
		open_door(data);
		mod_wall(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
	{
		data->player->step_len = STEP_LEN * SPRINT_MULTIPLIER;
		data->player->rotate_speed = ROTATE_SPEED * SPRINT_MULTIPLIER;
	}
	else
	{
		data->player->step_len = STEP_LEN;
		data->player->rotate_speed = ROTATE_SPEED;
	}
}

void	keyboard(void *param)
{
	t_game	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_forward(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_backward(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(data->player, data->player->rotate_speed);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(data->player, data->player->rotate_speed);
	keyboard_two(data);
}
