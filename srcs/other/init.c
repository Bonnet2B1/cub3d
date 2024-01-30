/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:12:06 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/30 18:19:03 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_game	game_data_init(void)
{
	t_game	data;

	data.x_chain = NULL;
	data.assets = NULL;
	data.gps = NULL;
	data.parsing = NULL;
	data.mlx = NULL;
	return (data);
}

t_parsing	*parsing_init(t_game *data)
{
	t_parsing	*parsing;

	parsing = x_malloc(&data->x_chain, sizeof(t_parsing));
	if (!parsing)
		exit_error(data, "malloc error");
	parsing->map_hole = 0;
	parsing->temp_map = NULL;
	parsing->north_path = NULL;
	parsing->south_path = NULL;
	parsing->west_path = NULL;
	parsing->east_path = NULL;
	return (parsing);
}

t_map	*map_init(t_game *data)
{
	t_map	*map;

	map = x_malloc(&data->x_chain, sizeof(t_map));
	if (!map)
		exit_error(data, "malloc error");
	map->map = NULL;
	map->height = -1;
	map->width = -1;
	return (map);
}

t_assets	*assets_init(t_game *data)
{
	t_assets	*assets;

	assets = x_malloc(&data->x_chain, sizeof(t_assets));
	if (!assets)
		exit_error(data, "malloc error");
	assets->north_img = NULL;
	assets->south_img = NULL;
	assets->west_img = NULL;
	assets->east_img = NULL;
	return (assets);
}

t_player	*player_init(t_game *data)
{
	t_player	*player;
	int			i;

	player = x_malloc(&data->x_chain, sizeof(t_player));
	if (!player)
		exit_error(data, "malloc error");
	player->minimap_img = NULL;
	player->x = -1;
	player->y = -1;
	player->angle = -1;
	player->front = ray_init(data, player);
	player->back = ray_init(data, player);
	player->left = ray_init(data, player);
	player->right = ray_init(data, player);
	player->ray = x_malloc(&data->x_chain, sizeof(t_ray *) * WINDOW_WIDTH);
	i = -1;
	while (++i < WINDOW_WIDTH)
		player->ray[i] = ray_init(data, player);
	return (player);
}
