/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_custom_assets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:31:16 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/31 17:31:34 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_custom_assets(t_game *data, t_assets *assets)
{
	assets->anubis_chill_img
		= asset_to_image(data, "assets/maze/anubis_chill.png");
	assets->anubis_not_happy_img
		= asset_to_image(data, "assets/maze/anubis_not_happy.png");
	assets->basic_wall_img
		= asset_to_image(data, "assets/maze/basic_wall.png");
	assets->door_img
		= asset_to_image(data, "assets/maze/door.png");
	assets->goal_img
		= asset_to_image(data, "assets/maze/goal.png");
	assets->mummy_left_img
		= asset_to_image(data, "assets/maze/mummy_left.png");
	assets->mummy_right_img
		= asset_to_image(data, "assets/maze/mummy_right.png");
	assets->peacock_img
		= asset_to_image(data, "assets/maze/peacock.png");
	assets->pillar_img
		= asset_to_image(data, "assets/maze/pillar.png");
	assets->sarcophagus_img
		= asset_to_image(data, "assets/maze/sarcophagus.png");
	assets->wall_w_hole_img
		= asset_to_image(data, "assets/maze/wall_w_hole.png");
}
