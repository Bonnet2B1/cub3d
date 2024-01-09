/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lazer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:36:58 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/08 17:33:04 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_lazer(t_game_data *data, t_ray *ray)
{
	int i;
	double lazer_pos_x;
	double lazer_pos_y;

	lazer_pos_y = *ray->y * data->gps->minimap_img_size;
	lazer_pos_x = *ray->x * data->gps->minimap_img_size;
	if (ray->lazer_img)
		mlx_delete_image(data->mlx, ray->lazer_img);
	ray->lazer_img = mlx_new_image(data->mlx, 1, 1);
	mlx_put_pixel(ray->lazer_img, 0, 0, 0xFF0);
	i = -1;
	printf("angle: %f\n", ray->angle);
	while(++i < ray->len * data->gps->minimap_img_size)
	{
		lazer_pos_y += sin(ray->angle);
		lazer_pos_x += cos(ray->angle);
		mlx_image_to_window(data->mlx, ray->lazer_img, lazer_pos_x, lazer_pos_y);
		ray->lazer_img->instances[i].z = 10;
	}
}
