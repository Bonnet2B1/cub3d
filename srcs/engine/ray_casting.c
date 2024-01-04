/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:25:08 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/04 20:50:11 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	trace_ray(t_game_data *data)
{
	t_player	*player;
	double		relative_y;
	double		relative_x;

	player = data->player;
	/* COLLISIONS CONTRE LES LIGNES VERTICALES */
		/* FIRST */
	relative_y = player->y - floor(player->y);
	relative_x = player->x - floor(player->x);
	(void)relative_x;
	(void)relative_y;
	player->ray->len = sqrt(pow(relative_x, 2) + pow(sin(player->angle), 2));
	printf("ray: %f\n", player->ray->len);
	if (player->ray->len >= 100)
		player->ray->len = 100;
		/* OTHERS */
	/* WALL */

}

void	draw_lazer(t_game_data *data, t_player *player, double angle)
{
	int i;
	double lazer_pos_x;
	double lazer_pos_y;

	lazer_pos_y = player->y * data->gps->minimap_img_size;
	lazer_pos_x = player->x * data->gps->minimap_img_size;
	mlx_delete_image(data->mlx, player->lazer_img);
	player->lazer_img = mlx_new_image(data->mlx, 1, 1);
	mlx_put_pixel(player->lazer_img, 0, 0, 0xFF0);
	i = -1;
	while(++i < player->ray->len * data->gps->minimap_img_size)
	{
		lazer_pos_y += sin(angle);
		lazer_pos_x += cos(angle);
		mlx_image_to_window(data->mlx, player->lazer_img, lazer_pos_x, lazer_pos_y);
		player->lazer_img->instances[i].z = 10;
	}
}

//calculs pour murs, afficher la dist entre joueur et mur pour tester si ça fonctionne

void	ray_casting(void *param)
{
	t_game_data	*data;

	data = param;
	trace_ray(data);
	draw_lazer(data, data->player, data->player->angle);
}
