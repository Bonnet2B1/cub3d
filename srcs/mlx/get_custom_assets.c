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
	assets->door_img
		= asset_to_image(data, "assets/maze/D.png");
	assets->goal_img
		= asset_to_image(data, "assets/maze/G.png");
	assets->spe_north_img
		= asset_to_image(data, "assets/maze/2_N.png");
	assets->spe_south_img
		= asset_to_image(data, "assets/maze/2_S.png");
	assets->mod_north_one_img
		= asset_to_image(data, "assets/maze/3_N.png");
	assets->mod_south_one_img
		= asset_to_image(data, "assets/maze/3_S.png");
	assets->mod_east_one_img
		= asset_to_image(data, "assets/maze/3_E.png");
	assets->mod_north_two_anim[0]
		= asset_to_image(data, "assets/maze/4_N_1.png");
	assets->mod_north_two_anim[1]
		= asset_to_image(data, "assets/maze/4_N_2.png");
	assets->mod_south_two_img
		= asset_to_image(data, "assets/maze/4_S.png");
	assets->mod_east_two_img
		= asset_to_image(data, "assets/maze/4_E.png");
}
