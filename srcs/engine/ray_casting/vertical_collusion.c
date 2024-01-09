/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_collusion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:48:53 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/08 20:24:24 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	looking_left(t_ray *ray, char **map)
{
	double	player_line;
	double	line_line;

	if (is_collision(map[][]))
		return (ray->len);
	while (!is_collision(map[][]))
	{
	}
	return (ray->len);
}

double	get_len_to_vertical_collision(t_game_data *data, t_ray *ray)
{
	if (ray->angle >= PI/2 && ray->angle <= 3*PI/2)
		return (looking_left(ray, data->gps->map));
	else
		return (looking_right(ray, data->gps->map));
}
