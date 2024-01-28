/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gride.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:11:39 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/27 16:13:56 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_gride(t_game_data *data, int img_size, int depth)
{
	int			i;
	int			j;
	int			k;
	mlx_image_t	*img;

	img = mlx_new_image(data->mlx, GRIDE_DOT_SIZE, GRIDE_DOT_SIZE);
	i = -1;
	while (i++ < GRIDE_DOT_SIZE)
	{
		j = -1;
		while (j++ < GRIDE_DOT_SIZE)
			mlx_put_pixel(img, i, j, 0x808080);
	}
	k = -1;
	i = -1;
	while (++i < data->gps->height)
	{
		j = -1;
		while (++j < data->gps->width)
		{
			mlx_image_to_window(data->mlx, img, j * img_size, i * img_size);
			img->instances[++k].z = depth;
			if (MINIMAP_ASSET_SIZE > 0)
			{
				mlx_image_to_window(data->mlx, img, j * img_size + img_size - GRIDE_DOT_SIZE,
					i * img_size + img_size - GRIDE_DOT_SIZE);
				img->instances[++k].z = depth;
				mlx_image_to_window(data->mlx, img, j * img_size + img_size - GRIDE_DOT_SIZE, i * img_size);
				img->instances[++k].z = depth;
				mlx_image_to_window(data->mlx, img, j * img_size, i * img_size + img_size - GRIDE_DOT_SIZE);
				img->instances[++k].z = depth;
			}
		}
	}
}
