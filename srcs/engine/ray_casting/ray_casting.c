/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:25:08 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/26 14:38:44 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	get_len(t_game_data *data, t_ray *ray)
{
	get_len_to_vertical_collision(data, ray->vertical);
	get_len_to_horizontal_collision(data, ray->horizontal);
	if (ray->horizontal->len < ray->vertical->len)
	{
		ray->one_piece_x = ray->horizontal->one_piece_x;
		ray->one_piece_y = ray->horizontal->one_piece_y;
		return (ray->horizontal->len);
	}
	else
	{
		ray->one_piece_x = ray->vertical->one_piece_x;
		ray->one_piece_y = ray->vertical->one_piece_y;
		return (ray->vertical->len);
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
}

void	get_ray_data(t_game_data *data, t_player *player)
{
	int		i;
	double	first_ray_angle;

	first_ray_angle = get_principal_measure(data->player->angle - ft_deg_to_rad(FOV/2));
	i = -1;
	printf("\n");
	while (++i < RAY_AMOUNT)
	{
		player->ray[i].angle = get_principal_measure(first_ray_angle + i * ft_deg_to_rad(FOV/RAY_AMOUNT));
		deep_ray_cpy(&player->ray[i]);
		player->ray[i].len = get_len(data, &player->ray[i]);
		printf("%d: x = %f, y = %f,x angle = %f\n", i, *player->ray[i].x, *player->ray[i].y, player->ray[i].angle);
		draw_lazer(data, &data->player->ray[i]);
	}
}

void	ray_casting(void *param)
{
	t_game_data	*data;

	data = param;
	get_ray_data(data, data->player);
}
