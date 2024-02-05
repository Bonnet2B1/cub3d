/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:48:46 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/04 20:09:29 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_player *player, double speed)
{
	player->angle -= speed;
	player->angle = get_principal_measure(player->angle);
}

void	rotate_right(t_player *player, double speed)
{
	player->angle += speed;
	player->angle = get_principal_measure(player->angle);
}
