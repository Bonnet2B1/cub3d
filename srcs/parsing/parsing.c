/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:15:45 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/11 19:18:56 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_parsing	*parsing(t_game_data *data, int argc, char **argv)
{
	t_parsing	*parsing;

	parsing = parsing_init(data);
	if (argc < 2)
		exit_error(data, ".cub file needed");
	if (argc > 2)
		exit_error(data, "too many arguments");
	check_file(data, argv[1]);
	parsing->file = extract_file_to_tab(data, argv[1]);
	format_error(data, parsing);
	data->gps = extract_data(data, parsing);
	verify_map_chars(data, data->gps->map);
	parsing->temp_map = map_w_null_background(&data->x_chain, data->gps->map);
	valid_way(data, parsing->temp_map,
		find_player_x(data->gps->map) + 1, find_player_y(data->gps->map) + 1);
	return (parsing);
}
