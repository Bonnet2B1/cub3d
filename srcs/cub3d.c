/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:43:15 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/06 19:54:08 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loops(t_game_data *data)
{
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_game_data	data;

	data = game_data_init();
	data.parsing = parsing(&data, argc, argv);
	(&(data))->mlx = mlx_init(1500, 1000, "cub3D", 0);
	load_assets(&data);
	display_minimap(&data, find_mimimap_img_size(data.gps->width,
			data.gps->height));
	loops(&data);
	free_n_exit(&data, 0);
}
