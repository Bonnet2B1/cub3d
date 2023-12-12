/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minimap_assets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:53:56 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/12 18:18:22 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_minimap_assets(t_game_data *data, t_assets *assets)
{
	assets->minimap_floor_img
		= asset_to_image(data, "assets/minimap/minimap_floor.png");
	assets->minimap_wall_img
		= asset_to_image(data, "assets/minimap/minimap_wall.png");
	assets->minimap_player_img
		= asset_to_image(data, "assets/minimap/minimap_player.png");
	assets->minimap_door_img
		= asset_to_image(data, "assets/minimap/minimap_door.png");
}
