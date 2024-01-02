/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:48:46 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/02 19:56:24 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_player *player)
{
	player->angle -= ROTATE_SPEED;
	player->angle = get_principal_measure(player->angle);
	printf("angle: %f\n", player->angle);
}

void	rotate_right(t_player *player)
{
	player->angle += ROTATE_SPEED;
	player->angle = get_principal_measure(player->angle);
	printf("angle: %f\n", player->angle);
}
