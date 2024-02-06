/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lazer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:36:58 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/06 12:21:21 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_lazer_next(t_game *data, t_ray *ray,
		double lazer_pos_x, double lazer_pos_y)
{
	int	i;

	i = -1;
	while (++i < ray->len * data->gps->minimap_img_size)
	{
		if (i + 1 > ray->instance_amount)
		{
			ray->instance_amount = i + 1;
			mlx_image_to_window(data->mlx, ray->ray_img, 0, 0);
		}
		ray->ray_img->instances[i].enabled = 1;
		lazer_pos_y += sin(ray->angle);
		ray->ray_img->instances[i].y = lazer_pos_y;
		lazer_pos_x += cos(ray->angle);
		ray->ray_img->instances[i].x = lazer_pos_x;
		ray->ray_img->instances[i].z = 30;
	}
}

void	draw_lazer(t_game *data, t_ray *ray)
{
	int		i;
	double	lazer_pos_x;
	double	lazer_pos_y;

	i = -1;
	while (++i < ray->instance_amount)
		ray->ray_img->instances[i].enabled = 0;
	lazer_pos_y = *ray->y * data->gps->minimap_img_size;
	lazer_pos_x = *ray->x * data->gps->minimap_img_size;
	if (!ray->ray_img)
	{
		ray->ray_img = mlx_new_image(data->mlx, 1, 1);
		mlx_put_pixel(ray->ray_img, 0, 0, 0xFFFFFF60);
		i = -1;
		while (++i < 1500)
		{
			mlx_image_to_window(data->mlx, ray->ray_img, 0, 0);
			ray->instance_amount = i + 1;
			ray->ray_img->instances[i].enabled = 0;
		}
	}
	i = -1;
	draw_lazer_next(data, ray, lazer_pos_x, lazer_pos_y);
}
