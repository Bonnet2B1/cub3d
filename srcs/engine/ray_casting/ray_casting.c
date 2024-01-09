/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:25:08 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/08 20:19:30 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	get_len(t_game_data *data, t_ray *ray)
{
	double	len_x;
	double	len_y;

	len_x = get_len_to_horizontal_collision(data, ray->horizontal);
	len_y = get_len_to_vertical_collision(data, ray->vertical);
	if (len_x < len_y)
		return (len_x);
	else
		return (len_y);
}

void	get_ray_data(t_game_data *data, t_player *player)
{
	int	i;

	i = -1;
	(void)data;
	while (++i < RAY_NUMBER)
	{
		deep_ray_cpy(&player->ray[i]);
		player->ray[i].angle = get_angle(player, i);
		// player->ray[i].angle = player->angle;
		player->ray[i].len = get_len(data, &player->ray[i]);
		// player->ray[i].len = 1;
	}
}

void	deep_ray_cpy(t_ray *ray)
{
	ray->horizontal->x = ray->x;
	ray->vertical->x = ray->x;
	ray->horizontal->y = ray->y;
	ray->vertical->y = ray->y;
	ray->horizontal->angle = ray->angle;
	ray->vertical->angle = ray->angle;
	ray->horizontal->one_piece_x = ray->x;
	ray->vertical->one_piece_x = ray->x;
	ray->horizontal->one_piece_y = ray->y;
	ray->vertical->one_piece_y = ray->y;
	ray->horizontal->len = 0;
	ray->vertical->len = 0;
	ray->horizontal->vertical = NULL;
	ray->vertical->vertical = NULL;
	ray->horizontal->horizontal = NULL;
	ray->vertical->horizontal = NULL;
}

void	ray_casting(void *param)
{
	int i;
	t_game_data	*data;

	data = param;
	get_ray_data(data, data->player);
	i = -1;
	while (++i < RAY_NUMBER)
	{
		draw_lazer(data, &data->player->ray[i]);
	}
}

void	trace_ray(t_game_data *data)
{
	t_player	*player;
	double		relative_y;
	double		relative_x;

	(void)relative_y;
	(void)relative_x;
	player = data->player;
	relative_y = player->y - floor(player->y);
	relative_x = player->x - floor(player->x);
	/* COLLISIONS CONTRE LES LIGNES VERTICALES */
		/* OTHERS */
			/* Measure len between two y lines */
	player->ray->len = sqrt(pow(1, 2) + pow(tan(player->angle), 2));
			/* Measure len between two x lines */
	player->ray->len = sqrt(pow(1, 2) + pow(1 / tan(player->angle), 2));
		/* FIRST */
			/* Measure len between player and first y line */
	if (player->angle < PI / 2 || player->angle > 3 * PI / 2)
		player->ray->len = (1 - relative_x) * sqrt(pow(1, 2) + pow(tan(player->angle), 2));
	else
		player->ray->len = relative_x * sqrt(pow(1, 2) + pow(tan(player->angle), 2));
			/* Measure len between player and first x line */
	if (player->angle < PI)
		player->ray->len = (1 - relative_y) * sqrt(pow(1, 2) + pow(1 / tan(player->angle), 2));
	else
		player->ray->len = relative_y * sqrt(pow(1, 2) + pow(1 / tan(player->angle), 2));
	/* WALL */

	/* SECU */
	if (player->ray->len > 100)
		player->ray->len = 100;
}