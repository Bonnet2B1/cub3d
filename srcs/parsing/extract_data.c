/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:40:17 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/17 22:38:23 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**get_rgb(t_game *data, char *line)
{
	char	**rgb;
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!ft_strchr(&line[i], ','))
		exit_error(data, "invalid color");
	rgb = ft_split(&data->x_chain, ft_strdup(&data->x_chain, &line[i]), ',');
	i = -1;
	while (rgb[++i])
	{
		if (!ft_str_is_num(rgb[i])
			|| ft_atoi_mod(rgb[i]) < 0 || ft_atoi_mod(rgb[i]) > 255
			|| i > 2)
			exit_error(data, "invalid color");
	}
	return (rgb);
}

t_map	*extract_map(t_game *data, t_parsing *parsing)
{
	t_map	*gps;

	if (!parsing->file[6])
		exit_error(data, "there is no map");
	gps = map_init(data);
	gps->map = &parsing->file[6];
	while (gps->map[++gps->height])
		if (gps->width < ft_strlen(gps->map[gps->height]))
			gps->width = ft_strlen(gps->map[gps->height]);
	while (gps->map[(int)++data->player->y])
	{
		data->player->x = -1;
		while (gps->map[(int)data->player->y][(int)++data->player->x])
			if (gps->map[(int)data->player->y][(int)data->player->x] == 'N'
				|| gps->map[(int)data->player->y][(int)data->player->x] == 'S'
				|| gps->map[(int)data->player->y][(int)data->player->x] == 'E'
				|| gps->map[(int)data->player->y][(int)data->player->x] == 'W')
				return (data->player->x += 0.5, data->player->y += 0.5, gps);
	}
	return (exit_error(data, "no player position"), NULL);
}

t_map	*extract_data(t_game *data, t_parsing *parsing)
{
	int	i;

	i = -1;
	while (++i < 6 && parsing->file[i])
	{
		if (ft_strncmp(parsing->file[i], "NO ", 3) == 0)
			parsing->north_path = ft_strdup(&data->x_chain, &parsing->file[i][3]);
		else if (ft_strncmp(parsing->file[i], "SO ", 3) == 0)
			parsing->south_path = ft_strdup(&data->x_chain, &parsing->file[i][3]);
		else if (ft_strncmp(parsing->file[i], "WE ", 3) == 0)
			parsing->west_path = ft_strdup(&data->x_chain, &parsing->file[i][3]);
		else if (ft_strncmp(parsing->file[i], "EA ", 3) == 0)
			parsing->east_path = ft_strdup(&data->x_chain, &parsing->file[i][3]);
		else if (ft_strncmp(parsing->file[i], "F ", 2) == 0)
			parsing->floor_rgb = get_rgb(data, &parsing->file[i][2]);
		else if (ft_strncmp(parsing->file[i], "C ", 2) == 0)
			parsing->ceiling_rgb = get_rgb(data, &parsing->file[i][2]);
		else
			exit_error(data, FILE_FORMAT);
	}
	return (extract_map(data, parsing));
}
