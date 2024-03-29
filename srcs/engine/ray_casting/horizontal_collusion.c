/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_collusion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:48:07 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/04 20:11:56 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	looking_left_up_h(t_ray *ray, t_map *gps)
{
	ray->side = 'S';
	ray->len = (*ray->y - floor(*ray->y))
		* sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
	ray->op_x = *ray->x - sqrt(pow(ray->len, 2)
			- pow(*ray->y - floor(*ray->y), 2));
	ray->op_y = floor(*ray->y);
	while (!is_collision(gps, (int)floor(ray->op_y) - 1,
			(int)floor(ray->op_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
		ray->op_x -= sqrt(pow(sqrt(pow(1, 2)
						+ pow(1 / tan(ray->angle), 2)), 2) - pow(1, 2));
		ray->op_y -= 1;
	}
	ray->sqrt_hit = ray->op_x - floor(ray->op_x);
	ray->map_x = (int)floor(ray->op_x);
	ray->map_y = (int)floor(ray->op_y) - 1;
	return (ray->len);
}

double	looking_left_down_h(t_ray *ray, t_map *gps)
{
	ray->side = 'N';
	ray->len = (1 - (*ray->y - floor(*ray->y)))
		* sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
	ray->op_x = *ray->x - sqrt(pow(ray->len, 2)
			- pow(1 - (*ray->y - floor(*ray->y)), 2));
	ray->op_y = floor(*ray->y) + 1;
	while (!is_collision(gps, (int)floor(ray->op_y), (int)floor(ray->op_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
		ray->op_x -= sqrt(pow(sqrt(pow(1, 2)
						+ pow(1 / tan(ray->angle), 2)), 2) - pow(1, 2));
		ray->op_y += 1;
	}
	ray->sqrt_hit = ray->op_x - floor(ray->op_x);
	ray->map_x = (int)floor(ray->op_x);
	ray->map_y = (int)floor(ray->op_y);
	return (ray->len);
}

double	looking_right_up_h(t_ray *ray, t_map *gps)
{
	ray->side = 'S';
	ray->len = (*ray->y - floor(*ray->y))
		* sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
	ray->op_x = *ray->x + sqrt(pow(ray->len, 2)
			- pow(*ray->y - floor(*ray->y), 2));
	ray->op_y = floor(*ray->y);
	while (!is_collision(gps, (int)floor(ray->op_y) - 1,
			(int)floor(ray->op_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
		ray->op_x += sqrt(pow(sqrt(pow(1, 2)
						+ pow(1 / tan(ray->angle), 2)), 2) - pow(1, 2));
		ray->op_y -= 1;
	}
	ray->sqrt_hit = ray->op_x - floor(ray->op_x);
	ray->map_x = (int)floor(ray->op_x);
	ray->map_y = (int)floor(ray->op_y) - 1;
	return (ray->len);
}

double	looking_right_down_h(t_ray *ray, t_map *gps)
{
	ray->side = 'N';
	ray->len = (1 - (*ray->y - floor(*ray->y)))
		* sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
	ray->op_x = *ray->x + sqrt(pow(ray->len, 2)
			- pow(1 - (*ray->y - floor(*ray->y)), 2));
	ray->op_y = floor(*ray->y) + 1;
	while (!is_collision(gps, (int)floor(ray->op_y), (int)floor(ray->op_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
		ray->op_x += sqrt(pow(sqrt(pow(1, 2)
						+ pow(1 / tan(ray->angle), 2)), 2) - pow(1, 2));
		ray->op_y += 1;
	}
	ray->sqrt_hit = ray->op_x - floor(ray->op_x);
	ray->map_x = (int)floor(ray->op_x);
	ray->map_y = (int)floor(ray->op_y);
	return (ray->len);
}

double	get_len_to_horizontal_collision(t_game *data, t_ray *ray)
{
	if (ray->angle >= M_PI / 2 && ray->angle <= M_PI)
		return (looking_left_down_h(ray, data->gps));
	else if (ray->angle >= M_PI && ray->angle <= 3 * M_PI / 2)
		return (looking_left_up_h(ray, data->gps));
	else if (ray->angle >= 0 && ray->angle <= M_PI / 2)
		return (looking_right_down_h(ray, data->gps));
	else
		return (looking_right_up_h(ray, data->gps));
}
