/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:15:45 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/11 21:51:28 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_image_t	*extract_img(t_game_data *data, char *path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		exit_error(&data->x_chain, "invalid path to texture");
	img = mlx_texture_to_image(data->mlx, texture);
	return (img);
}

t_assets	*get_assets(t_game_data *data, t_parsing *parsing)
{
	t_assets	*assets;

	assets = assets_init(data);
	assets->north_img = extract_img(data, parsing->north_path);
	assets->south_img = extract_img(data, parsing->south_path);
	assets->west_img = extract_img(data, parsing->west_path);
	assets->east_img = extract_img(data, parsing->east_path);
	return (assets);
}

void	parsing(t_game_data *data, int argc, char **argv)
{
	t_parsing	*parsing;

	parsing = parsing_init(data);
	if (argc < 2)
		exit_error(&data->x_chain, ".cub file needed");
	if (argc > 2)
		exit_error(&data->x_chain, "too many arguments");
	check_file(data, argv[1]);
	parsing->file = extract_file_to_tab(data, argv[1]);
	format_error(data, parsing);
	data->gps = extract_data(data, parsing);
	verify_map_chars(data, data->gps->map);
	parsing->temp_map = map_w_null_background(&data->x_chain, data->gps->map);
	valid_way(&data->x_chain, parsing->temp_map,
		find_player_x(data->gps->map) + 1, find_player_y(data->gps->map) + 1);
	data->assets = get_assets(data, parsing);
}
