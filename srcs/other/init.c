/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:12:06 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/11 21:50:05 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_game_data	game_data_init(void)
{
	t_game_data	data;

	data.x_chain = NULL;
	return (data);
}

t_parsing	*parsing_init(t_game_data *data)
{
	t_parsing	*parsing;

	parsing = x_malloc(&data->x_chain, sizeof(t_parsing));
	if (!parsing)
		exit_error(&data->x_chain, "malloc error");
	parsing->map_hole = 0;
	parsing->temp_map = NULL;
	parsing->north_path = NULL;
	parsing->south_path = NULL;
	parsing->west_path = NULL;
	parsing->east_path = NULL;
	parsing->floor_color = NULL;
	parsing->ceiling_color = NULL;
	return (parsing);
}

t_map	*map_init(t_game_data *data)
{
	t_map	*map;

	map = x_malloc(&data->x_chain, sizeof(t_map));
	if (!map)
		exit_error(&data->x_chain, "malloc error");
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	return (map);
}

t_assets	*assets_init(t_game_data *data)
{
	t_assets	*assets;

	assets = x_malloc(&data->x_chain, sizeof(t_assets));
	if (!assets)
		exit_error(&data->x_chain, "malloc error");
	assets->north_img = NULL;
	assets->south_img = NULL;
	assets->west_img = NULL;
	assets->east_img = NULL;
	assets->floor_trgb[0] = -1;
	assets->floor_trgb[1] = -1;
	assets->floor_trgb[2] = -1;
	assets->floor_trgb[3] = -1;
	assets->ceiling_trgb[0] = -1;
	assets->ceiling_trgb[1] = -1;
	assets->ceiling_trgb[2] = -1;
	assets->ceiling_trgb[3] = -1;
	return (assets);
}
