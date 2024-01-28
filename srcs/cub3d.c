/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:43:15 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/27 17:45:02 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game_data	data;

	data = game_data_init();
	data.parsing = parsing(&data, argc, argv);
	data.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", 0);
	load_assets(&data);
	create_minimap(&data, find_mimimap_img_size(data.gps->width,
			data.gps->height));
	data.big_mask = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT); // - ranger ça
	mlx_image_to_window(data.mlx, data.big_mask, 0, 0); // - ranger ça
	data.big_mask->instances->z = 0; // - ranger ça
	loops(&data);
	free_n_exit(&data, 0);
}
