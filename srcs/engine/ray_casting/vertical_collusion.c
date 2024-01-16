/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_collusion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:48:53 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/16 17:54:15 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	looking_left(t_ray *ray, char **map)
{
	(void)map;
	ray->one_piece_x = floor(*ray->x);
	ray->one_piece_y = (*ray->y) - tan(ray->angle);
	ray->len = (*ray->x - floor(*ray->x)) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	printf("Checking in x: %d, y: %d\n", (int)ray->one_piece_x - 1, (int)ray->one_piece_y);
	printf("one piece = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
	// if (is_collision(map[(int)ray->one_piece_y][(int)ray->one_piece_x - 1])) /* check de collisions */
		return (ray->len);
	// while (!is_collision(map[(int)ray->one_piece_y][(int)ray->one_piece_x - 1])) /* check de collisions jusqu'a mur */
	// {
	// 	//ajouter len a onepiece x et y
	// 	ray->one_piece_x -= 1;
	// 	ray->one_piece_y += tan(ray->angle);
	// 	//update ray len
	// 	ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	// }
	// return (ray->len);
}

double	looking_right(t_ray *ray, char **map)
{
	(void)map;
	ray->one_piece_x = floor(*ray->x) + 1;
	ray->one_piece_y = (*ray->y) + tan(ray->angle);
	ray->len = (*ray->x - floor(*ray->x) - 1) * sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	printf("Checking in x: %d, y: %d\n", (int)ray->one_piece_x, (int)ray->one_piece_y);
	printf("one piece = x: %f, y: %f\n", ray->one_piece_x, ray->one_piece_y);
	// if (is_collision(map[(int)ray->one_piece_y][(int)ray->one_piece_x])) /* check de collisions */
		return (ray->len);
	// while (!is_collision(map[(int)ray->one_piece_y][(int)ray->one_piece_x])) /* check de collisions jusqu'a mur */
	// {
	// 	//ajouter len a onepiece x et y
	// 	ray->one_piece_x += 1;
	// 	ray->one_piece_y += tan(ray->angle);
	// 	//update ray len
	// 	ray->len += sqrt(pow(1, 2) + pow(tan(ray->angle), 2));
	// }
	// return (ray->len);
}

double	get_len_to_vertical_collision(t_game_data *data, t_ray *ray)
{
	if (ray->angle >= PI / 2 && ray->angle <= 3 * PI / 2)
		return (looking_left(ray, data->gps->map));
	else
		return (looking_right(ray, data->gps->map));
}
