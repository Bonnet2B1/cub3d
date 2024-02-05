/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_assets_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:52:21 by momox             #+#    #+#             */
/*   Updated: 2024/02/04 19:53:35 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_dancing_ra(t_game *data, t_ray *ray, int ray_idx)
{
	if (data->assets->frame <= ANIMATION_SPEED / 6)
		put_line(data, ray, ray_idx, data->assets->dancing_ra_imgs[0]);
	else if (data->assets->frame <= 2 * (ANIMATION_SPEED / 6))
		put_line(data, ray, ray_idx, data->assets->dancing_ra_imgs[1]);
	else if (data->assets->frame <= 3 * (ANIMATION_SPEED / 6))
		put_line(data, ray, ray_idx, data->assets->dancing_ra_imgs[2]);
	else if (data->assets->frame <= 4 * (ANIMATION_SPEED / 6))
		put_line(data, ray, ray_idx, data->assets->dancing_ra_imgs[3]);
	else if (data->assets->frame <= 5 * (ANIMATION_SPEED / 6))
		put_line(data, ray, ray_idx, data->assets->dancing_ra_imgs[4]);
	else if (data->assets->frame <= ANIMATION_SPEED)
		put_line(data, ray, ray_idx, data->assets->dancing_ra_imgs[5]);
}
