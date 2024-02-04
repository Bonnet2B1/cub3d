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

#include "../../cub3d.h"


void put_line(t_game *data, mlx_image_t *big_mask, t_ray *ray, int ray_idx, mlx_image_t *img)
{
	int const		line_height = WINDOW_WIDTH / ray->len;
	int const		first_pixel = (WINDOW_HEIGHT - line_height) / 2;
	int const		last_pixel = WINDOW_HEIGHT - first_pixel;
	double const	ratio = 1.0 * ASSET_SIZE / line_height;
	int				actual_pixel;
	double			img_x;
	double			img_y;

	img_x = ray->sqrt_hit * ASSET_SIZE;
	if (img_x > ASSET_SIZE - 1)
		img_x = ASSET_SIZE - 1;
	actual_pixel = first_pixel;
	img_y = 0;
	if (actual_pixel < 0)
	{
		img_y += ratio * abs(actual_pixel);
		actual_pixel = 0;
	}
	int dark_index = ray->len * 50;
	if (dark_index > 255)
		dark_index = 255;
	while (actual_pixel < last_pixel && actual_pixel < WINDOW_HEIGHT)
	{
		if (img_y > ASSET_SIZE - 1)
			img_y = ASSET_SIZE - 1;
		mlx_put_pixel(big_mask, ray_idx, actual_pixel, get_color_coord(round(img_x), round(img_y), img));
		mlx_put_pixel(data->assets->darkness_textures_mask, ray_idx, actual_pixel, data->assets->dark_shade[dark_index]);
		actual_pixel++;
		img_y += ratio;
	}
}

void	put_wall(t_game *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->north_img);
	else if (ray->side == 'S')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->south_img);
	else if (ray->side == 'E')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->east_img);
	else if (ray->side == 'W')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->west_img);
}

void	put_spe(t_game *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N' || ray->side == 'S')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->pillar_img);
	if (ray->side == 'W' || ray->side == 'E')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->peacock_img);
}

void	put_mod_one(t_game *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N' || ray->side == 'S')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->sarcophagus_img);
	else if (ray->side == 'E')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->anubis_chill_img);
	else if (ray->side == 'W')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->basic_wall_img);
}

void	put_mod_two(t_game *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N' || ray->side == 'S')
	{
		if (data->assets->frame < ANIMATION_SPEED / 2)
			put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->mummy_left_img);
		else
			put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->mummy_right_img);
	}
	else if (ray->side == 'E')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->anubis_not_happy_img);
	else if (ray->side == 'W')
		put_line(data, data->assets->textures_mask, ray, ray_idx, data->assets->wall_w_hole_img);
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
		else if (ray[ray_idx]->type == '2')
			put_spe(data, ray[ray_idx], ray_idx);
		else if (ray[ray_idx]->type == '3')
			put_mod_one(data, ray[ray_idx], ray_idx);
		else if (ray[ray_idx]->type == '4')
			put_mod_two(data, ray[ray_idx], ray_idx);
		else if (ray[ray_idx]->type == 'G')
			put_line(data, data->assets->textures_mask, ray[ray_idx], ray_idx, data->assets->goal_img);
		else if (ray[ray_idx]->type == 'D')
			put_line(data, data->assets->textures_mask, ray[ray_idx], ray_idx, data->assets->door_img);
	}
}

void	clear(mlx_image_t *texture_mask, mlx_image_t *darkness_texture_mask)
{
	int i;
	int j;

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

