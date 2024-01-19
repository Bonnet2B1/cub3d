/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_collusion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:48:53 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/18 23:50:04 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	looking_left_up(t_ray *ray, char **map)
{
	// (void)map;
	printf("LEFT UP\n\n");
	ray->one_piece_x = floor(*ray->x);
	ray->len = (*ray->x - floor(*ray->x)) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->one_piece_y = (*ray->y) - sqrt(pow(ray->len, 2) - (pow(*ray->x - floor(*ray->x), 2)));
	printf("Checking in x: %d, y: %d\n", (int)ray->one_piece_x - 1, (int)ray->one_piece_y);
	printf("one piece = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
	while (!is_collision(map[(int)ray->one_piece_y][(int)(ray->one_piece_x - 1)]))
	{
		printf("ONEPIECE = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->one_piece_x -= 1;
		ray->one_piece_y -= sqrt(pow(ray->len, 2) - pow(1, 2));
	}
	return (ray->len);
}

double	looking_left_down(t_ray *ray, char **map)
{
	// (void)map;
	printf("LEFT DOWN\n\n");
	ray->one_piece_x = floor(*ray->x);
	ray->len = (*ray->x - floor(*ray->x)) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->one_piece_y = (*ray->y) + sqrt(pow(ray->len, 2) - (pow(*ray->x - floor(*ray->x), 2)));
	printf("Checking in x: %d, y: %d\n", (int)ray->one_piece_x - 1, (int)ray->one_piece_y);
	printf("one piece = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
	while (!is_collision(map[(int)ray->one_piece_y][(int)ray->one_piece_x - 1]))
	{
		printf("ONEPIECE = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->one_piece_x -= 1;
		ray->one_piece_y += sqrt(pow(ray->len, 2) - pow(1, 2));
	}
	return (ray->len);
}

double	looking_right_up(t_ray *ray, char **map)
{
	// (void)map;
	printf("RIGHT UP\n\n");
	ray->one_piece_x = floor(*ray->x) + 1;
	ray->len = (*ray->x - floor(*ray->x) - 1) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->one_piece_y = (*ray->y) - sqrt(pow(ray->len, 2) - pow(*ray->x - floor(*ray->x), 2));
	printf("Checking in x: %d, y: %d\n", (int)ray->one_piece_x, (int)ray->one_piece_y);
	printf("one piece = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
	while (!is_collision(map[(int)ray->one_piece_y][(int)ray->one_piece_x + 1]))
	{
		printf("ONEPIECE = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->one_piece_x += 1;
		ray->one_piece_y -= sqrt(pow(ray->len, 2) - pow(1, 2));
	}
	return (ray->len);
}

double	looking_right_down(t_ray *ray, char **map)
{
	// (void)map;
	printf("RIGHT DOWN\n\n");
	ray->one_piece_x = floor(*ray->x) + 1;
	ray->len = (*ray->x - floor(*ray->x) - 1) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	ray->one_piece_y = (*ray->y) + sqrt(pow(ray->len, 2) - pow(*ray->x - floor(*ray->x), 2));
	printf("Checking in x: %d, y: %d\n", (int)ray->one_piece_x, (int)ray->one_piece_y);
	printf("one piece = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
	while (!is_collision(map[(int)ray->one_piece_y][(int)ray->one_piece_x + 1]))
	{
		printf("ONEPIECE = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
		ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
		ray->one_piece_x += 1;
		// if (ray->angle != 0)
		ray->one_piece_y += sqrt(pow(ray->len, 2) - pow(1, 2));
	}
	return (ray->len);
}

double	get_len_to_vertical_collision(t_game_data *data, t_ray *ray)
{
	printf("ray->angle = %f\n", ray->angle);
	if (ray->angle >= PI / 2 && ray->angle <= PI)
		return (looking_left_down(ray, data->gps->map));
	else if (ray->angle >= PI && ray->angle <= 3 * PI / 2)
		return (looking_left_up(ray, data->gps->map));
	else if (ray->angle >= 0 && ray->angle <= PI / 2)
		return (looking_right_down(ray, data->gps->map));
	else
		return (looking_right_up(ray, data->gps->map));
}
