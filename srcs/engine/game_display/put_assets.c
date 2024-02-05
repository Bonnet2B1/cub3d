/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:52:21 by momox             #+#    #+#             */
/*   Updated: 2024/02/04 19:53:35 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_line(t_game *data, t_ray *ray, int ray_idx, mlx_image_t *img)
{
	int		actual_pixel;
	double	img_x;
	double	img_y;
	int		dark_idx;

	img_x = fmin(ray->sqrt_hit * ASSET_SIZE, ASSET_SIZE - 1);
	img_y = 0;
	actual_pixel = ((WINDOW_HEIGHT - (WINDOW_WIDTH / ray->len)) / 2);
	if (actual_pixel < 0)
	{
		img_y += (1.0 * ASSET_SIZE / (WINDOW_WIDTH / ray->len))
			* abs(actual_pixel);
		actual_pixel = 0;
	}
	dark_idx = fmin(ray->len * 50, 255);
	while (actual_pixel < (WINDOW_HEIGHT
			- ((WINDOW_HEIGHT - (WINDOW_WIDTH / ray->len)) / 2))
		&& actual_pixel < WINDOW_HEIGHT)
	{
		img_y = fmin(img_y, ASSET_SIZE - 1);
		mlx_put_pixel(data->assets->textures_mask, ray_idx, actual_pixel,
			get_color(round(img_x), round(img_y), img));
		mlx_put_pixel(data->assets->darkness_textures_mask, ray_idx,
			actual_pixel++, data->assets->dark_shade[dark_idx]);
		img_y += (1.0 * ASSET_SIZE / (WINDOW_WIDTH / ray->len));
	}
}

// void	put_line(t_game *data, t_ray *ray, int ray_idx, mlx_image_t *img)
// {
// 	int const		line_height = WINDOW_WIDTH / ray->len;
// 	int const		first_pixel = (WINDOW_HEIGHT - line_height) / 2;
// 	int const		last_pixel = WINDOW_HEIGHT - first_pixel;
// 	double const	ratio = 1.0 * ASSET_SIZE / line_height;
// 	int				actual_pixel;
// 	double			img_x;
// 	double			img_y;

// 	img_x = ray->sqrt_hit * ASSET_SIZE;
// 	if (img_x > ASSET_SIZE - 1)
// 		img_x = ASSET_SIZE - 1;
// 	actual_pixel = first_pixel;
// 	img_y = 0;
// 	if (actual_pixel < 0)
// 	{
// 		img_y += ratio * abs(actual_pixel);
// 		actual_pixel = 0;
// 	}
// 	int dark_idx = ray->len * 50;
// 	if (dark_idx > 255)
// 		dark_idx = 255;
// 	while (actual_pixel < last_pixel && actual_pixel < WINDOW_HEIGHT)
// 	{
// 		if (img_y > ASSET_SIZE - 1)
// 			img_y = ASSET_SIZE - 1;
// 		mlx_put_pixel(data->assets->textures_mask, ray_idx, actual_pixel,
// 			get_color_coord(round(img_x), round(img_y), img));
// 		mlx_put_pixel(data->assets->darkness_textures_mask, ray_idx,
// 			actual_pixel, data->assets->dark_shade[dark_idx]);
// 		actual_pixel++;
// 		img_y += ratio;
// 	}
// }

void	put_wall(t_game *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N')
		put_line(data, ray, ray_idx, data->assets->north_img);
	else if (ray->side == 'S')
		put_line(data, ray, ray_idx, data->assets->south_img);
	else if (ray->side == 'E')
		put_line(data, ray, ray_idx, data->assets->east_img);
	else if (ray->side == 'W')
		put_line(data, ray, ray_idx, data->assets->west_img);
}

void	put_spe(t_game *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N' || ray->side == 'S')
		put_line(data, ray, ray_idx, data->assets->pillar_img);
	if (ray->side == 'W' || ray->side == 'E')
		put_line(data, ray, ray_idx, data->assets->peacock_img);
}

void	put_mod_one(t_game *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N' || ray->side == 'S')
		put_line(data, ray, ray_idx, data->assets->sarcophagus_img);
	else if (ray->side == 'E')
		put_line(data, ray, ray_idx, data->assets->anubis_chill_img);
	else if (ray->side == 'W')
		put_line(data, ray, ray_idx, data->assets->basic_wall_img);
}

void	put_mod_two(t_game *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N' || ray->side == 'S')
	{
		if (data->assets->frame < ANIMATION_SPEED / 2)
			put_line(data, ray, ray_idx, data->assets->mummy_left_img);
		else
			put_line(data, ray, ray_idx, data->assets->mummy_right_img);
	}
	else if (ray->side == 'E')
		put_line(data, ray, ray_idx, data->assets->anubis_not_happy_img);
	else if (ray->side == 'W')
		put_line(data, ray, ray_idx, data->assets->wall_w_hole_img);
}
