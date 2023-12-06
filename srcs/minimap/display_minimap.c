/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:53:32 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/06 19:59:21 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_minimap(t_game_data *data, int img_size)
{
	int	i;
	int	j;

	mlx_resize_image(data->assets->minimap_floor_img, img_size, img_size);
	mlx_resize_image(data->assets->minimap_wall_img, img_size, img_size);
	mlx_resize_image(data->assets->minimap_player_img, img_size, img_size);
	i = -1;
	while (++i < data->gps->width)
	{
		j = -1;
		while (++j < data->gps->height)
		{
			if (data->gps->map[j][i] == '1')
				mlx_image_to_window(data->mlx, data->assets->minimap_wall_img,
					i * img_size, j * img_size);
			else if (data->gps->map[j][i] == '0')
				mlx_image_to_window(data->mlx, data->assets->minimap_floor_img,
					i * img_size, j * img_size);
			else if (data->gps->map[j][i] == 'N' || data->gps->map[j][i] == 'S'
				|| data->gps->map[j][i] == 'E' || data->gps->map[j][i] == 'W')
				mlx_image_to_window(data->mlx, data->assets->minimap_player_img,
					i * img_size, j * img_size);
		}
	}
}
