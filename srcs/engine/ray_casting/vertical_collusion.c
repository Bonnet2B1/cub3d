/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_collusion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:48:53 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/21 03:47:49 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	looking_left_up(t_ray *ray, t_map *gps)
{
	printf("VERTICAL\n");
	ray->len = (*ray->x - floor(*ray->x)) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->one_piece_x = floor(*ray->x);
	ray->one_piece_y = *ray->y - sqrt(pow(ray->len, 2) - (pow(*ray->x - floor(*ray->x), 2)));
	while (!is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x) - 1))
	{
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->one_piece_x -= 1;
		ray->one_piece_y -= sqrt(pow(sqrt(pow(1, 2) + pow(tan(ray->angle), 2)), 2) - pow(1, 2));
	}
	return (ray->len);
}

double	looking_left_down(t_ray *ray, t_map *gps)
{
	printf("VERTICAL\n");
	ray->len = (*ray->x - floor(*ray->x)) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->one_piece_x = floor(*ray->x);
	ray->one_piece_y = *ray->y + sqrt(pow(ray->len, 2) - (pow(*ray->x - floor(*ray->x), 2)));
	while (!is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x) - 1))
	{
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->one_piece_x -= 1;
		ray->one_piece_y += sqrt(pow(sqrt(pow(1, 2) + pow(tan(ray->angle), 2)), 2) - pow(1, 2));
	}
	return (ray->len);
}

double	looking_right_up(t_ray *ray, t_map *gps)
{
	printf("VERTICAL\n");
	ray->len = (1 - (*ray->x - floor(*ray->x))) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->one_piece_x = floor(*ray->x) + 1;
	ray->one_piece_y = *ray->y - sqrt(pow(ray->len, 2) - pow((1 - (*ray->x - floor(*ray->x))), 2));
	is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x));
	while (!is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->one_piece_x += 1;
		ray->one_piece_y -= sqrt(pow(sqrt(pow(1, 2) + pow(tan(ray->angle), 2)), 2) - pow(1, 2));
	}
	return (ray->len);
}

double	looking_right_down(t_ray *ray, t_map *gps)
{
	printf("VERTICAL\n");
	ray->len = (1 - (*ray->x - floor(*ray->x))) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->one_piece_x = floor(*ray->x) + 1;
	ray->one_piece_y = *ray->y + sqrt(pow(ray->len, 2) - pow((1 - (*ray->x - floor(*ray->x))), 2));
	is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x));
	while (!is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->one_piece_x += 1;
		ray->one_piece_y += sqrt(pow(sqrt(pow(1, 2) + pow(tan(ray->angle), 2)), 2) - pow(1, 2));
	}
	return (ray->len);
}

double	get_len_to_vertical_collision(t_game_data *data, t_ray *ray)
{
	if (ray->angle >= PI / 2 && ray->angle <= PI)
		return (looking_left_down(ray, data->gps));
	else if (ray->angle >= PI && ray->angle <= 3 * PI / 2)
		return (looking_left_up(ray, data->gps));
	else if (ray->angle >= 0 && ray->angle <= PI / 2)
		return (looking_right_down(ray, data->gps));
	else
		return (looking_right_up(ray, data->gps));
}
