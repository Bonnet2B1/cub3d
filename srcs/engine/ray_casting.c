/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:25:08 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/04 15:37:38 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	trace_ray(t_game_data *data, double angle)
{
	(void)data;
	if (angle > 0 && angle < PI)
	{
		printf("%f\n", sqrt(pow(sin(angle) - data->player->y, 2) + pow(cos(angle) - data->player->x, 2)));
	}
}

void	draw_lazer(t_game_data *data, t_player *player, double angle)
{
	int i;
	double lazer_pos_x;
	double lazer_pos_y;

	if (!player->lazer_inited)
	{
		i = -1;
		while(++i < 10)
		{
			player->lazer_img[i] = mlx_new_image(data->mlx, 1, 1);
			mlx_put_pixel(player->lazer_img[i], 0, 0, 0xFF0);
			lazer_pos_y = player->y * data->gps->minimap_img_size;
			lazer_pos_x = player->x * data->gps->minimap_img_size;
			lazer_pos_y += sin(angle);
			lazer_pos_x += cos(angle);
			printf("x: %f, y: %f\n", lazer_pos_x, lazer_pos_y);
			mlx_image_to_window(data->mlx, player->lazer_img[i], lazer_pos_x, lazer_pos_y);
			player->lazer_img[i]->instances->z = 10;
		}
		player->lazer_inited = 1;
	}
	lazer_pos_y = player->y * data->gps->minimap_img_size;
	lazer_pos_x = player->x * data->gps->minimap_img_size;
	i = -1;
	while(++i < 10)
	{
		lazer_pos_y += sin(angle);
		lazer_pos_x += cos(angle);
		data->player->lazer_img[i]->instances->x = lazer_pos_x;
		data->player->lazer_img[i]->instances->y = lazer_pos_y;
	}
}

//calculs pour murs, afficher la dist entre joueur et mur pour tester si ça fonctionne

void	ray_casting(void *param)
{
	t_game_data	*data;

	data = param;
	trace_ray(data, data->player->angle);
	draw_lazer(data, data->player, data->player->angle);
	// maths(data, data->player, data->ray);
}
