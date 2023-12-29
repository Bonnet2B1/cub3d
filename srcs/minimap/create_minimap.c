/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:53:32 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/29 16:40:48 by edelarbr         ###   ########.fr       */
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
	while (data->gps->map[++i])
	{
		j = -1;
		while (data->gps->map[i][++j])
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
	while (data->gps->map[++i])
	{
		j = -1;
		while (data->gps->map[i][++j])
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
	while (data->gps->map[++i])
	{
		j = -1;
		while (data->gps->map[i][++j])
		{
			if (data->gps->map[i][j] == 'N'
				|| data->gps->map[i][j] == 'S'
				|| data->gps->map[i][j] == 'W'
				|| data->gps->map[i][j] == 'E')
			{
				mlx_image_to_window(data->mlx, data->player->minimap_img,
					(j + 0.5) * img_size,
					(i + 0.5) * img_size);
				data->player->minimap_img->instances[++k].z = depth;
				return (set_player_angle(data->player, data->gps->map[i][j]), (void)0);
			}
		}
	}
}

void	create_minimap(t_game_data *data, int img_size)
{
	data->gps->minimap_img_size = img_size;
	mlx_resize_image(data->assets->minimap_floor_img, img_size, img_size);
	mlx_resize_image(data->assets->minimap_wall_img, img_size, img_size);
	mlx_resize_image(data->assets->minimap_door_img, img_size, img_size);
	mlx_resize_image(data->player->minimap_img, img_size / 5, img_size / 5);
	display_floor(data, img_size, 0);
	display_walls(data, img_size, 2);
	display_doors(data, img_size, 2);
	display_gride(data, img_size, 1);
	put_player(data, img_size, 1);
}
