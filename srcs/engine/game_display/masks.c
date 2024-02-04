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
	double	dark_index;

	i = WINDOW_HEIGHT / 2;
	dark_index = 255;
	while (i >= 0)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			mlx_put_pixel(mask, j, i, assets->dark_shade[(int)round(dark_index)]);
		i--;
		if (i < 400 && dark_index > 0)
			dark_index -= 0.5;
	}
	i = WINDOW_HEIGHT / 2;
	dark_index = 255;
	while (i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			mlx_put_pixel(mask, j, i, assets->dark_shade[(int)round(dark_index)]);
		i++;
		if (i > WINDOW_HEIGHT - 400 && dark_index > 0)
			dark_index -= 0.5;
	}
}

void	display_vignette(t_assets *assets, mlx_image_t *mask)
{
	int i;
	int j;
	int dark_index;
	int center_x = WINDOW_WIDTH / 2;
	int center_y = WINDOW_HEIGHT / 2;
	int max_distance = sqrt(center_x * center_x + center_y * center_y);
	int distance;

	i = -1;
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			distance = sqrt((center_x - j) * (center_x - j) + (center_y - i) * (center_y - i));
			dark_index = (int)((double)distance / max_distance * 255);
			if (dark_index > 255)
				dark_index = 255;
			mlx_put_pixel(mask, j, i, assets->dark_shade[dark_index]);
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
