/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:46:14 by momox             #+#    #+#             */
/*   Updated: 2024/02/04 19:46:35 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_imgs(t_game *data, int img_size)
{
	int	i;
	int	j;

	data->assets->minimap_floor_img
		= mlx_new_image(data->mlx, img_size, img_size);
	data->assets->minimap_door_img
		= mlx_new_image(data->mlx, img_size, img_size);
	data->assets->minimap_wall_img
		= mlx_new_image(data->mlx, img_size, img_size);
	data->assets->minimap_goal_img
		= mlx_new_image(data->mlx, img_size, img_size);
	i = -1;
	while (++i < img_size)
	{
		j = -1;
		while (++j < img_size)
		{
			mlx_put_pixel(data->assets->minimap_floor_img, i, j, 0xFFFFFFFF);
			mlx_put_pixel(data->assets->minimap_door_img, i, j, 0x636363FF);
			mlx_put_pixel(data->assets->minimap_wall_img, i, j, 0x3b3b3bFF);
			mlx_put_pixel(data->assets->minimap_goal_img, i, j, 0xffd700FF);
		}
	}
	data->player->minimap_img = mlx_new_image(data->mlx, 1, 1);
	mlx_put_pixel(data->player->minimap_img, 0, 0, 0x000000FF);
}
