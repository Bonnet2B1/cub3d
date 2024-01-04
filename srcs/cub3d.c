/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:43:15 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/04 19:40:24 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game_data	data;

	data = game_data_init();
	data.parsing = parsing(&data, argc, argv);
	(&(data))->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", 0);
	load_assets(&data);
	create_minimap(&data, find_mimimap_img_size(data.gps->width,
			data.gps->height));
	data.player->ray = x_malloc(&data.x_chain, sizeof(t_ray)); // ! temp
	data.player->lazer_img = mlx_new_image(data.mlx, 1, 1); // ! temp
	mlx_put_pixel(data.player->lazer_img, 0, 0, 0xFF0); // ! temp
	loops(&data);
	free_n_exit(&data, 0);
}
