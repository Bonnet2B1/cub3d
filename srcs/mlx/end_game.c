/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:36:00 by momox             #+#    #+#             */
/*   Updated: 2024/02/05 19:39:39 by momox            ###   ########.fr       */
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
		printf("! Congratulation !\n");
		printf("You have escaped th\n");
		printf("[1]    12274 abort      ./cub3D big.cub\n");
		free_n_exit(data, 0);
	}
}
