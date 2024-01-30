/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:25:08 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/30 18:19:40 by momox            ###   ########.fr       */
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
		ray->map_x = ray->horizontal->map_x;
		ray->map_y = ray->horizontal->map_y;
		ray->side = ray->horizontal->side;
		return (ray->horizontal->len);
	}
	else
	{
		ray->one_piece_x = ray->vertical->one_piece_x;
		ray->one_piece_y = ray->vertical->one_piece_y;
		ray->map_x = ray->vertical->map_x;
		ray->map_y = ray->vertical->map_y;
		ray->side = ray->vertical->side;
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

	first_ray_angle = get_principal_measure(data->player->angle - ft_deg_to_rad((float)FOV/2));
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		player->ray[i]->angle = get_principal_measure(first_ray_angle + i * ft_deg_to_rad((float)FOV/(WINDOW_WIDTH - 1)));
		deep_ray_cpy(player->ray[i]);
		player->ray[i]->len = get_len(data, player->ray[i]);
	}
	i = 0;
	while(i < WINDOW_WIDTH)
	{
		draw_lazer(data, data->player->ray[i]);
		i += 15;
	}
}

void	ray_casting(void *param)
{
	t_game_data	*data;

	data = param;
	get_ray_data(data, data->player);
	game_display(data);
}
