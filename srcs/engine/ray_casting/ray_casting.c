/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:25:08 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/31 17:29:00 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	get_len(t_game *data, t_ray *ray)
{
	get_len_to_horizontal_collision(data, ray->h);
	get_len_to_vertical_collision(data, ray->v);
	if (ray->h->len < ray->v->len)
	{
		ray->op_x = ray->h->op_x;
		ray->op_y = ray->h->op_y;
		ray->map_x = ray->h->map_x;
		ray->map_y = ray->h->map_y;
		ray->sqrt_hit = ray->h->sqrt_hit;
		ray->side = ray->h->side;
		ray->type = data->gps->map[ray->h->map_y][ray->h->map_x];
		return (ray->h->len);
	}
	else
	{
		ray->op_x = ray->v->op_x;
		ray->op_y = ray->v->op_y;
		ray->map_x = ray->v->map_x;
		ray->map_y = ray->v->map_y;
		ray->sqrt_hit = ray->v->sqrt_hit;
		ray->side = ray->v->side;
		ray->type = data->gps->map[ray->v->map_y][ray->v->map_x];
		return (ray->v->len);
	}
}

void	deep_ray_cpy(t_ray *ray)
{
	ray->h->x = ray->x;
	ray->v->x = ray->x;
	ray->h->y = ray->y;
	ray->v->y = ray->y;
	ray->h->angle = ray->angle;
	ray->v->angle = ray->angle;
}

void	get_ray_data(t_game *data, t_player *player)
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
	t_game	*data;

	data = param;
	get_ray_data(data, data->player);
	game_display(data);
}
