/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:25:08 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/25 20:10:35 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	get_len(t_game_data *data, t_ray *ray)
{
	double	len_x;
	double	len_y;

	len_y = fabs(get_len_to_vertical_collision(data, ray->vertical));
	len_x = fabs(get_len_to_horizontal_collision(data, ray->horizontal));
	if (len_x < len_y)
	{
		ray->one_piece_x = ray->horizontal->one_piece_x;
		ray->one_piece_y = ray->horizontal->one_piece_y;
		ray->len = ray->horizontal->len;
		return (len_x);
	}
	else
	{
		ray->one_piece_x = ray->vertical->one_piece_x;
		ray->one_piece_y = ray->vertical->one_piece_y;
		ray->len = ray->vertical->len;
		return (len_y);
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
	ray->horizontal->one_piece_x = 0;
	ray->vertical->one_piece_x = 0;
	ray->horizontal->one_piece_y = 0;
	ray->vertical->one_piece_y = 0;
	ray->horizontal->len = 0;
	ray->vertical->len = 0;
	ray->horizontal->vertical = NULL;
	ray->vertical->vertical = NULL;
	ray->horizontal->horizontal = NULL;
	ray->vertical->horizontal = NULL;
}

void	get_ray_data(t_game_data *data, t_player *player)
{
	int		i;
	double	first_ray_angle;

	i = -1;
	first_ray_angle = data->player->angle - ft_deg_to_rad(FOV/RAY_AMOUNT/2);
	while (++i < RAY_AMOUNT)
	{
		deep_ray_cpy(&player->ray[i]);
		player->ray[i].angle = first_ray_angle + i * ft_deg_to_rad(FOV/RAY_AMOUNT);
		player->ray[i].len = get_len(data, &player->ray[i]);
		draw_lazer(data, &data->player->ray[i]);
	}
}

void	ray_casting(void *param)
{
	t_game_data	*data;

	data = param;
	get_ray_data(data, data->player);
}
