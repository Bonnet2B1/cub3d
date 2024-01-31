/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:34:25 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/30 20:02:23 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

void	put_floor_and_ceiling(t_game *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_HEIGHT / 2)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			mlx_put_pixel(data->big_mask, j, i, data->assets->ceiling_trgb);
	}
	while (i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			mlx_put_pixel(data->big_mask, j, i, data->assets->floor_trgb);
		i++;
	}
}

void put_line(mlx_image_t *big_mask, t_ray *ray, int ray_idx, mlx_image_t *img)
{
	int		line_height;
	int		first_pixel;
	int		last_pixel;
	double	ratio;
	int		actual_pixel;
	double	img_x;
	double	img_y;

	img_x = ray->sqrt_hit * ASSET_SIZE;
	if (img_x > ASSET_SIZE - 1)
		img_x = ASSET_SIZE - 1;
	line_height = WINDOW_WIDTH / ray->len;
	ratio = 1.0 * ASSET_SIZE / line_height;
	first_pixel = (WINDOW_HEIGHT - line_height) / 2;
	last_pixel = WINDOW_HEIGHT - first_pixel;
	actual_pixel = first_pixel;
	img_y = 0;
	if (actual_pixel < 0)
	{
		img_y += ratio * abs(actual_pixel);
		actual_pixel = 0;
	}
	while (actual_pixel < last_pixel && actual_pixel < WINDOW_HEIGHT)
	{
		if (img_y > ASSET_SIZE - 1)
			img_y = ASSET_SIZE - 1;
		mlx_put_pixel(big_mask, ray_idx, actual_pixel, get_color_coord(round(img_x), round(img_y), img));
		actual_pixel++;
		img_y += ratio;
	}
}

void	put_wall(t_game *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N')
		put_line(data->big_mask, ray, ray_idx, data->assets->north_img);
	if (ray->side == 'S')
		put_line(data->big_mask, ray, ray_idx, data->assets->south_img);
	if (ray->side == 'E')
		put_line(data->big_mask, ray, ray_idx, data->assets->east_img);
	if (ray->side == 'W')
		put_line(data->big_mask, ray, ray_idx, data->assets->west_img);
}

void	put_assets(t_game *data, t_ray **ray)
{
	int	ray_idx;

	ray_idx = -1;
	while (++ray_idx < WINDOW_WIDTH)
	{
		ray[ray_idx]->len *= cos(get_principal_measure(data->player->angle - ray[ray_idx]->angle));
		if (ray[ray_idx]->type == '1')
			put_wall(data, ray[ray_idx], ray_idx);
		else if (ray[ray_idx]->type == 'C')
			put_line(data->big_mask, ray[ray_idx], ray_idx, data->assets->closed_door_img);
	}
}

void	game_display(t_game *data)
{
	put_floor_and_ceiling(data);
	put_assets(data, data->player->ray);
}

