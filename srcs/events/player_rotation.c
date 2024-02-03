/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:48:46 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/04 17:35:23 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_player *player, double speed)
{
	player->angle -= speed;
	player->angle = get_principal_measure(player->angle);
}

void	rotate_right(t_player *player , double speed)
{
	player->angle += speed;
	player->angle = get_principal_measure(player->angle);
}
