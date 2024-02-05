/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:09:48 by momox             #+#    #+#             */
/*   Updated: 2024/02/04 20:09:50 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	animation(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	data->assets->frame++;
	if (data->assets->frame > ANIMATION_SPEED)
		data->assets->frame = 0;
}
