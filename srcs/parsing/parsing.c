/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:15:45 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/11 00:15:26 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	format_error(t_game_data *data, t_parsing *parsing)
{
	if (ft_strncmp(parsing->file[0], "NO ", 3) != 0
		|| ft_strncmp(parsing->file[1], "SO ", 3) != 0
		|| ft_strncmp(parsing->file[2], "WE ", 3) != 0
		|| ft_strncmp(parsing->file[3], "EA ", 3) != 0
		|| ft_strncmp(parsing->file[4], "", 1) != 0
		|| ft_strncmp(parsing->file[5], "F ", 2) != 0
		|| ft_strncmp(parsing->file[6], "C ", 2) != 0
		|| ft_strncmp(parsing->file[7], "", 1) != 0
		|| !parsing->file[8])
		exit_error(&data->x_chain, FILE_FORMAT);
}

void	extract_data(t_game_data *data, t_parsing *parsing)
{
	parsing->north_path = ft_strdup(&data->x_chain, parsing->file[0] + 3);
	parsing->south_path = ft_strdup(&data->x_chain, parsing->file[1] + 3);
	parsing->west_path = ft_strdup(&data->x_chain, parsing->file[2] + 3);
	parsing->east_path = ft_strdup(&data->x_chain, parsing->file[3] + 3);
	parsing->floor_color = ft_strdup(&data->x_chain, parsing->file[5] + 2);
	parsing->ceiling_color = ft_strdup(&data->x_chain, parsing->file[6] + 2);
	data->map = &parsing->file[8];
}

void	verify_map_chars(t_game_data *data, char **map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map[++i] && player <= 1)
	{
		j = -1;
		while (map[i][++j] && player <= 1)
		{
			if (map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'W'
				&& map[i][j] != 'E' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != ' ')
				exit_error(&data->x_chain, "unauthorized character in map");
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				player++;
		}
	}
	if (player < 1)
		exit_error(&data->x_chain, "no player in map");
	if (player > 1)
		exit_error(&data->x_chain, "too many players in map");
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
	extract_data(data, parsing);
	verify_map_chars(data, data->map);
	parsing->temp_map = map_w_null_background(&data->x_chain, data->map);
	valid_way(&data->x_chain, parsing->temp_map,
		find_player_x(data->map) + 1, find_player_y(data->map) + 1);
}
