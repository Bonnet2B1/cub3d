/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:43:15 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/04 19:01:46 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_minimap(t_game_data *data, int size)
{
	int			i;
	int			j;

	mlx_resize_image(data->assets->minimap_floor_img, size, size);
	mlx_resize_image(data->assets->minimap_wall_img, size, size);
	mlx_resize_image(data->assets->minimap_player_img, size, size);
	i = -1;
	while (++i < data->gps->width)
	{
		j = -1;
		while (++j < data->gps->height)
		{
			if (data->gps->map[j][i] == '1')
				mlx_image_to_window(data->mlx, data->assets->minimap_wall_img,
					i * size, j * size);
			else if (data->gps->map[j][i] == '0')
				mlx_image_to_window(data->mlx, data->assets->minimap_floor_img,
					i * size, j * size);
			else if (data->gps->map[j][i] == 'N' || data->gps->map[j][i] == 'S'
				|| data->gps->map[j][i] == 'E' || data->gps->map[j][i] == 'W')
				mlx_image_to_window(data->mlx, data->assets->minimap_player_img,
					i * size, j * size);
		}
	}
}

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
	display_minimap(&data, 16);
	loops(&data);
	free_n_exit(&data, 0);
}
