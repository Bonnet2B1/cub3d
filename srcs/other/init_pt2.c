/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pt2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:05:09 by momox             #+#    #+#             */
/*   Updated: 2024/01/30 18:18:07 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_ray	*ray_init(t_game *data, t_player *player)
{
	t_ray	*ray;

	ray = x_malloc(&data->x_chain, sizeof(t_ray));
	ray->v = x_malloc(&data->x_chain, sizeof(t_ray));
	ray->h = x_malloc(&data->x_chain, sizeof(t_ray));
	ray->instance_amount = 0;
	ray->x = &player->x;
	ray->y = &player->y;
	ray->ray_img = NULL;
	return (ray);
}
