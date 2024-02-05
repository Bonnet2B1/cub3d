/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:54:14 by momox             #+#    #+#             */
/*   Updated: 2024/02/04 19:55:45 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	display_background(t_assets *assets, mlx_image_t *mask)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_HEIGHT / 2)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			mlx_put_pixel(mask, j, i, assets->ceiling_trgb);
		}
	}
	while (i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			mlx_put_pixel(mask, j, i, assets->floor_trgb);
		i++;
	}
}

void	display_darkness_background(t_assets *assets, mlx_image_t *mask)
{
	int		i;
	int		j;
	double	dark_idx;

	i = WINDOW_HEIGHT / 2 + 1;
	dark_idx = 255;
	while (--i >= 0)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			mlx_put_pixel(mask, j, i, assets->dark_shade[(int)dark_idx]);
		if (i < 400 && dark_idx > 0)
			dark_idx -= 0.5;
	}
	i = WINDOW_HEIGHT / 2 - 1;
	dark_idx = 255;
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			mlx_put_pixel(mask, j, i, assets->dark_shade[(int)dark_idx]);
		if (i > WINDOW_HEIGHT - 400 && dark_idx > 0)
			dark_idx -= 0.5;
	}
}

void	display_vignette(t_assets *assets, mlx_image_t *mask)
{
	int	i;
	int	j;
	int	dark_idx;
	int	max_distance;
	int	distance;

	max_distance = sqrt(WINDOW_WIDTH / 2 * WINDOW_WIDTH / 2
			+ WINDOW_HEIGHT / 2 * WINDOW_HEIGHT / 2);
	i = -1;
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			distance = sqrt((WINDOW_WIDTH / 2 - j) * (WINDOW_WIDTH / 2 - j)
					+ (WINDOW_HEIGHT / 2 - i) * (WINDOW_HEIGHT / 2 - i));
			dark_idx = (int)((double)distance / max_distance * 255);
			if (dark_idx > 255)
				dark_idx = 255;
			mlx_put_pixel(mask, j, i, assets->dark_shade[dark_idx]);
		}
	}
}

mlx_image_t	*init_mask(t_game *data, int depth)
{
	mlx_image_t	*mask;

	mask = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(data->mlx, mask, 0, 0);
	mask->instances->z = depth;
	return (mask);
}

void	load_masks(t_game *data, t_assets *assets)
{
	data->assets->background_mask = init_mask(data, 0);
	data->assets->textures_mask = init_mask(data, 2);
	display_background(assets, assets->background_mask);
	if (DARKNESS_EFFECT)
	{
		data->assets->darkness_background_mask = init_mask(data, 1);
		data->assets->darkness_textures_mask = init_mask(data, 3);
		data->assets->vignette_mask = init_mask(data, 4);
		display_darkness_background(assets, assets->darkness_background_mask);
		display_vignette(assets, assets->vignette_mask);
	}
}
