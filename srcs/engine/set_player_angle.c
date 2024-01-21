/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:18:02 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/21 02:02:59 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_angle(t_player *player, char c)
{
	if (c == 'E')
		player->angle = 0;
	else if (c == 'S')
		player->angle = PI / 2;
	else if (c == 'W')
		player->angle = PI;
	else if (c == 'N')
		player->angle = 3 * PI / 2;
}

// /* et t'en peux plus là ? T'as trop envie de chier ? chie toi dessus */
// ?????? completement fou toi
// C'est ton easter egg nullos
