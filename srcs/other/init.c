/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:12:06 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/05 19:12:22 by momox            ###   ########.fr       */
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
	data.mouse = 0;
	data.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", 0);
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

void	assets_init_two(t_assets *assets)
{
	assets->north_img = NULL;
	assets->south_img = NULL;
	assets->west_img = NULL;
	assets->east_img = NULL;
	assets->minimap_wall_img = NULL;
	assets->minimap_door_img = NULL;
	assets->minimap_goal_img = NULL;
	assets->anubis_chill_img = NULL;
	assets->anubis_not_happy_img = NULL;
	assets->basic_wall_img = NULL;
	assets->door_img = NULL;
	assets->goal_img = NULL;
	assets->collapse_img = NULL;
	assets->mummy_left_img = NULL;
	assets->mummy_right_img = NULL;
	assets->peacock_img = NULL;
	assets->pillar_img = NULL;
	assets->sarcophagus_img = NULL;
	assets->wall_w_hole_img = NULL;
	assets->background_mask = NULL;
	assets->darkness_background_mask = NULL;
	assets->textures_mask = NULL;
	assets->darkness_textures_mask = NULL;
	assets->vignette_mask = NULL;
}

t_assets	*assets_init(t_game *data)
{
	t_assets	*assets;
	int			i;

	assets = x_malloc(&data->x_chain, sizeof(t_assets));
	if (!assets)
		exit_error(data, "malloc error");
	assets->frame = 0;
	i = -1;
	while (++i < 4)
		assets->dancing_ra_imgs[i] = NULL;
	i = -1;
	while (++i < 256)
		assets->dark_shade[i] = create_rgbt(0, 0, 0, i);
	assets_init_two(assets);
	return (assets);
}
