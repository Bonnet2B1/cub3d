/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_collusion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:48:07 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/21 17:10:17 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	looking_left_up_h(t_ray *ray, t_map *gps)
{
	printf("LEFT UP\n\n");
	printf("HORIZONTAL\n");
	ray->len = (*ray->y - floor(*ray->y)) * sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
	ray->one_piece_x = *ray->x - sqrt(pow(ray->len, 2) - pow(*ray->y - floor(*ray->y), 2));
	ray->one_piece_y = floor(*ray->y);
	while (!is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x)))
	{
		// printf("onepiece y = %f\n onepiece x = %f\n", ray->one_piece_y, ray->one_piece_x);
		// printf("len = %f\n", ray->len);
		ray->len += sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
		ray->one_piece_x -= sqrt(pow(sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2)), 2) - pow(1, 2));
		ray->one_piece_y -= 1;
	}
	return (ray->len);
}

double	looking_left_down_h(t_ray *ray, t_map *gps)
{
	printf("LEFT DOWN\n\n");
	printf("HORIZONTAL\n");
	ray->len = (*ray->y - floor(*ray->y)) * sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
	ray->one_piece_x = *ray->x - sqrt(pow(ray->len, 2) - pow(*ray->y - floor(*ray->y), 2));
	ray->one_piece_y = floor(*ray->y) + 1;
	// printf("len = %f\n", ray->len);
	while (!is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x)))
	{
		// printf("onepiece y = %f\n onepiece x = %f\n", ray->one_piece_y, ray->one_piece_x);
		// printf("len = %f\n\n", ray->len);
		ray->len += sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
		ray->one_piece_x -= sqrt(pow(sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2)), 2) - pow(1, 2));
		ray->one_piece_y += 1;
	}
	printf("\n\n");
	return (ray->len);
}
//le mur droit segfault
double	looking_right_up_h(t_ray *ray, t_map *gps)
{
	printf("RIGHT UP\n");
	printf("HORIZONTAL\n");
	ray->len = (1 - (*ray->y - floor(*ray->y))) * sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
	ray->one_piece_x = *ray->x + sqrt(pow(ray->len, 2) - pow((1 - (*ray->y - floor(*ray->y))), 2));
	ray->one_piece_y = floor(*ray->y) - 1;
	is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x));
	while (!is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
		ray->one_piece_x += sqrt(pow(sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2)), 2) - pow(1, 2));
		ray->one_piece_y -= 1;
	}
	printf("\n\n");
	return (ray->len);
}

double	looking_right_down_h(t_ray *ray, t_map *gps)
{
	printf("RIGHT DOWN\n");
	printf("HORIZONTAL\n");
	ray->len = (1 - (*ray->y - floor(*ray->y))) * sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
	ray->one_piece_x = *ray->x + sqrt(pow(ray->len, 2) - pow((1 - (*ray->y - floor(*ray->y))), 2));
	ray->one_piece_y = floor(*ray->y) + 1;
	is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x));
	while (!is_collision(gps, (int)floor(ray->one_piece_y), (int)floor(ray->one_piece_x)))
	{
		ray->len += sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2));
		ray->one_piece_x += sqrt(pow(sqrt(pow(1, 2) + pow(1 / tan(ray->angle), 2)), 2) - pow(1, 2));
		ray->one_piece_y += 1;
	}
	printf("\n\n");
	return (ray->len);
}

double	get_len_to_horizontal_collision(t_game_data *data, t_ray *ray)
{
	if (ray->angle >= PI / 2 && ray->angle <= PI)
		return (looking_left_down_h(ray, data->gps));
	else if (ray->angle >= PI && ray->angle <= 3 * PI / 2)
		return (looking_left_up_h(ray, data->gps));
	else if (ray->angle >= 0 && ray->angle <= PI / 2)
		return (looking_right_down_h(ray, data->gps));
	else
		return (looking_right_up_h(ray, data->gps));
}
