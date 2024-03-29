/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_collusion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:48:53 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/04 20:10:20 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	looking_left_up_v(t_ray *ray, t_map *gps)
{
	ray->side = 'E';
	ray->len = (*ray->x - floor(*ray->x))
		* sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->op_x = floor(*ray->x);
	ray->op_y = *ray->y - sqrt(pow(ray->len, 2)
			- (pow(*ray->x - floor(*ray->x), 2)));
	while (!is_collision(gps, (int)floor(ray->op_y), (int)floor(ray->op_x) - 1))
	{
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->op_x -= 1;
		ray->op_y -= sqrt(pow(sqrt(pow(1, 2)
						+ pow(tan(ray->angle), 2)), 2) - pow(1, 2));
	}
	ray->sqrt_hit = ray->op_y - floor(ray->op_y);
	ray->map_x = (int)floor(ray->op_x) - 1;
	ray->map_y = (int)floor(ray->op_y);
	return (ray->len);
}

double	looking_left_down_v(t_ray *ray, t_map *gps)
{
	ray->side = 'E';
	ray->len = (*ray->x - floor(*ray->x))
		* sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->op_x = floor(*ray->x);
	ray->op_y = *ray->y + sqrt(pow(ray->len, 2)
			- (pow(*ray->x - floor(*ray->x), 2)));
	while (!is_collision(gps, (int)floor(ray->op_y), (int)floor(ray->op_x) - 1))
	{
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->op_x -= 1;
		ray->op_y += sqrt(pow(sqrt(pow(1, 2)
						+ pow(tan(ray->angle), 2)), 2) - pow(1, 2));
	}
	ray->sqrt_hit = ray->op_y - floor(ray->op_y);
	ray->map_x = (int)floor(ray->op_x) - 1;
	ray->map_y = (int)floor(ray->op_y);
	return (ray->len);
}

double	looking_right_up_v(t_ray *ray, t_map *gps)
{
	ray->side = 'W';
	ray->len = (1 - (*ray->x - floor(*ray->x)))
		* sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->op_x = floor(*ray->x) + 1;
	ray->op_y = *ray->y - sqrt(pow(ray->len, 2)
			- pow((1 - (*ray->x - floor(*ray->x))), 2));
	while (!is_collision(gps, (int)floor(ray->op_y), (int)floor(ray->op_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->op_x += 1;
		ray->op_y -= sqrt(pow(sqrt(pow(1, 2)
						+ pow(tan(ray->angle), 2)), 2) - pow(1, 2));
	}
	ray->sqrt_hit = ray->op_y - floor(ray->op_y);
	ray->map_x = (int)floor(ray->op_x);
	ray->map_y = (int)floor(ray->op_y);
	return (ray->len);
}

double	looking_right_down_v(t_ray *ray, t_map *gps)
{
	ray->side = 'W';
	ray->len = (1 - (*ray->x - floor(*ray->x)))
		* sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->op_x = floor(*ray->x) + 1;
	ray->op_y = *ray->y + sqrt(pow(ray->len, 2)
			- pow((1 - (*ray->x - floor(*ray->x))), 2));
	while (!is_collision(gps, (int)floor(ray->op_y), (int)floor(ray->op_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->op_x += 1;
		ray->op_y += sqrt(pow(sqrt(pow(1, 2)
						+ pow(tan(ray->angle), 2)), 2) - pow(1, 2));
	}
	ray->sqrt_hit = ray->op_y - floor(ray->op_y);
	ray->map_x = (int)floor(ray->op_x);
	ray->map_y = (int)floor(ray->op_y);
	return (ray->len);
}

double	get_len_to_vertical_collision(t_game *data, t_ray *ray)
{
	if (ray->angle >= M_PI / 2 && ray->angle <= M_PI)
		return (looking_left_down_v(ray, data->gps));
	else if (ray->angle >= M_PI && ray->angle <= 3 * M_PI / 2)
		return (looking_left_up_v(ray, data->gps));
	else if (ray->angle >= 0 && ray->angle <= M_PI / 2)
		return (looking_right_down_v(ray, data->gps));
	else
		return (looking_right_up_v(ray, data->gps));
}
