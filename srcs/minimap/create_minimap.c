/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:53:32 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/04 19:46:05 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_walls(t_game *data, int img_size, int depth)
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
			if (data->gps->map[i][j] == '1' || data->gps->map[i][j] == '2'
				|| data->gps->map[i][j] == '3')
			{
				mlx_image_to_window(data->mlx, data->assets->minimap_wall_img,
					j * img_size, i * img_size);
				data->assets->minimap_wall_img->instances[++k].z = depth;
			}
		}
	}
}

void	display_doors(t_game *data, int img_size, int depth)
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
			if (data->gps->map[i][j] == 'D')
			{
				mlx_image_to_window(data->mlx, data->assets->minimap_door_img,
					j * img_size, i * img_size);
				data->assets->minimap_door_img->instances[++k].z = depth;
			}
		}
	}
}

void	display_goal(t_game *data, int img_size, int depth)
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
			if (data->gps->map[i][j] == 'G')
			{
				mlx_image_to_window(data->mlx, data->assets->minimap_goal_img,
					j * img_size, i * img_size);
				data->assets->minimap_goal_img->instances[++k].z = depth;
			}
		}
	}
}

void	put_player(t_game *data, double img_size, int depth)
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
					(j + 0.5) * img_size, (i + 0.5) * img_size);
				data->player->minimap_img->instances[++k].z = depth;
				set_player_angle(data->player, data->gps->map[i][j]);
				data->gps->map[i][j] = '0';
				return ;
			}
		}
	}
}

void	create_minimap(t_game *data, int img_size)
{
	data->gps->minimap_img_size = img_size;
	create_imgs(data, img_size);
	display_walls(data, img_size, 22);
	display_doors(data, img_size, 22);
	display_goal(data, img_size, 22);
	put_player(data, img_size, 21);
}
