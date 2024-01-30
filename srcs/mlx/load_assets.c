/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:47:57 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/04 18:10:12 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_assets(t_game *data)
{
	data->assets = assets_init(data);
	get_dot_ber_assets(data, data->assets, data->parsing);
	get_minimap_assets(data, data->assets);
}
