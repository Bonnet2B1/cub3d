/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:47:57 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/31 17:30:31 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_assets(t_game *data)
{
	data->assets = assets_init(data);
	get_dot_cub_assets(data, data->assets, data->parsing);
	get_custom_assets(data, data->assets);
}
