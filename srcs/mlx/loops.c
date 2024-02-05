/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:54 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/18 21:52:30 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	end_game(void *param)
{
	t_game		*data;
	t_player	*player;

	data = (t_game *)param;
	player = data->player;
	player->front->angle = player->angle;
	deep_ray_cpy(player->front);
	player->front->len = get_len(data, player->front);
	if (player->front->type == 'G' && player->front->len <= 0.5)
	{
		printf("[1]    12274 abort      ./cub3D big.cub\n");
		free_n_exit(data, 0);
	}
}

void	loops(t_game *data)
{
	mlx_loop_hook(data->mlx, keyboard, data);
	mlx_loop_hook(data->mlx, mouse, data);
	mlx_loop_hook(data->mlx, ray_casting, data);
	mlx_loop_hook(data->mlx, animation, data);
	mlx_loop_hook(data->mlx, end_game, data);
	mlx_loop(data->mlx);
}
