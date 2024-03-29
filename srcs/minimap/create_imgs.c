/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:46:14 by momox             #+#    #+#             */
/*   Updated: 2024/02/05 15:23:20 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_imgs(t_game *data, int img_size)
{
	int	i;
	int	j;

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
			mlx_put_pixel(data->assets->minimap_door_img, i, j, 0x63636360);
			mlx_put_pixel(data->assets->minimap_wall_img, i, j, 0x3b3b3b60);
			mlx_put_pixel(data->assets->minimap_goal_img, i, j, 0xffd70060);
		}
	}
	data->player->minimap_img = mlx_new_image(data->mlx, 1, 1);
	mlx_put_pixel(data->player->minimap_img, 0, 0, 0x000000FF);
}
