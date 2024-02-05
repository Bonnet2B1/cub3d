/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:34:25 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/04 19:54:03 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_assets(t_game *data, t_ray **ray)
{
	int	ray_idx;

	ray_idx = -1;
	while (++ray_idx < WINDOW_WIDTH)
	{
		ray[ray_idx]->len *= cos(get_principal_measure
				(data->player->angle - ray[ray_idx]->angle));
		if (ray[ray_idx]->type == '1')
			put_wall(data, ray[ray_idx], ray_idx);
		else if (ray[ray_idx]->type == '2')
			put_spe(data, ray[ray_idx], ray_idx);
		else if (ray[ray_idx]->type == '3')
			put_mod_one(data, ray[ray_idx], ray_idx);
		else if (ray[ray_idx]->type == '4')
			put_mod_two(data, ray[ray_idx], ray_idx);
		else if (ray[ray_idx]->type == 'G')
			put_line(data, data->assets->textures_mask,
				ray[ray_idx], ray_idx, data->assets->goal_img);
		else if (ray[ray_idx]->type == 'D')
			put_line(data, data->assets->textures_mask,
				ray[ray_idx], ray_idx, data->assets->door_img);
	}
}

void	clear(mlx_image_t *texture_mask, mlx_image_t *darkness_texture_mask)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_put_pixel(texture_mask, j, i, 0);
			mlx_put_pixel(darkness_texture_mask, j, i, 0);
			j++;
		}
		i++;
	}
}

void	game_display(t_game *data)
{
	clear(data->assets->textures_mask, data->assets->darkness_textures_mask);
	put_assets(data, data->player->ray);
}
