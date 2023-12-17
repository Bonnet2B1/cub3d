/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:53:32 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/17 19:28:20 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_floor(t_game_data *data, int img_size, int depth)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	while (++i < data->gps->height)
	{
		j = -1;
		while (++j < data->gps->width)
		{
			mlx_image_to_window(data->mlx, data->assets->minimap_floor_img,
				j * img_size, i * img_size);
			data->assets->minimap_floor_img->instances[++k].z = depth;
		}
	}
}

void	display_walls(t_game_data *data, int img_size, int depth)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	while (++i < data->gps->height)
	{
		j = -1;
		while (++j < data->gps->width)
		{
			if (data->gps->map[i][j] == '1')
			{
				mlx_image_to_window(data->mlx, data->assets->minimap_wall_img,
					j * img_size, i * img_size);
				data->assets->minimap_wall_img->instances[++k].z = depth;
			}
		}
	}
}

void	display_doors(t_game_data *data, int img_size, int depth)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	while (++i < data->gps->height)
	{
		j = -1;
		while (++j < data->gps->width)
		{
			if (data->gps->map[i][j] == '2')
			{
				mlx_image_to_window(data->mlx, data->assets->minimap_door_img,
					j * img_size, i * img_size);
				data->assets->minimap_door_img->instances[++k].z = depth;
			}
		}
	}
}

void	put_player(t_game_data *data, int img_size, int depth)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	while (++i < data->gps->height)
	{
		j = -1;
		while (++j < data->gps->width)
		{
			if (data->gps->map[i][j] == 'N'
				|| data->gps->map[i][j] == 'S'
				|| data->gps->map[i][j] == 'W'
				|| data->gps->map[i][j] == 'E')
			{
				mlx_image_to_window(data->mlx, data->assets->minimap_player_img,
					j * img_size, i * img_size);
				data->assets->minimap_player_img->instances[++k].z = depth;
				return ;
			}
		}
	}
}

void	display_gride(t_game_data *data, int img_size, int depth) // ! temp
{
	int			i;
	int			j;
	int			k;
	mlx_image_t	*img;

	img = mlx_new_image(data->mlx, img_size / 10, img_size / 10);
	i = -1;
	while (i++ < img_size / 10)
	{
		j = -1;
		while (j++ < img_size / 10)
			mlx_put_pixel(img, i, j, 0x808080);
	}
	k = -1;
	i = -1;
	while (++i < data->gps->height)
	{
		j = -1;
		while (++j < data->gps->width)
		{
			mlx_image_to_window(data->mlx, img, j * img_size, i * img_size);
			img->instances[++k].z = depth;
		}
	}
}

void	display_minimap(t_game_data *data, int img_size)
{
	data->gps->minimap_img_size = img_size;
	mlx_resize_image(data->assets->minimap_floor_img, img_size, img_size);
	mlx_resize_image(data->assets->minimap_wall_img, img_size, img_size);
	mlx_resize_image(data->assets->minimap_player_img, img_size, img_size);
	mlx_resize_image(data->assets->minimap_door_img, img_size, img_size);
	display_floor(data, img_size, 0);
	display_walls(data, img_size, 2);
	display_doors(data, img_size, 2);
	display_gride(data, img_size, 1); // ! temp
	put_player(data, img_size, 1);
}
