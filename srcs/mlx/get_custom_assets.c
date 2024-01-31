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
	assets->closed_door_img
		= asset_to_image(data, "assets/custom/C.png");
}
