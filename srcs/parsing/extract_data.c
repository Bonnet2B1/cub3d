/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:40:17 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/17 17:56:05 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**get_rgb(t_game_data *data, char *line)
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

t_map	*extract_data(t_game_data *data, t_parsing *parsing)
{
	t_map	*gps;

	gps = map_init(data);
	parsing->north_path = ft_strdup(&data->x_chain, &parsing->file[0][3]);
	parsing->south_path = ft_strdup(&data->x_chain, &parsing->file[1][3]);
	parsing->west_path = ft_strdup(&data->x_chain, &parsing->file[2][3]);
	parsing->east_path = ft_strdup(&data->x_chain, &parsing->file[3][3]);
	parsing->floor_rgb = get_rgb(data, &parsing->file[4][2]);
	parsing->ceiling_rgb = get_rgb(data, &parsing->file[5][2]);
	gps->map = &parsing->file[6];
	while (gps->map[++gps->height])
		if (gps->width < ft_strlen(gps->map[gps->height]))
			gps->width = ft_strlen(gps->map[gps->height]);
	while (gps->map[(int)++gps->py])
	{
		gps->px = -1;
		while (gps->map[(int)gps->py][(int)++gps->px])
			if (gps->map[(int)gps->py][(int)gps->px] == 'N'
				|| gps->map[(int)gps->py][(int)gps->px] == 'S'
				|| gps->map[(int)gps->py][(int)gps->px] == 'E'
				|| gps->map[(int)gps->py][(int)gps->px] == 'W')
				return (gps);
	}
	return (exit_error(data, "no player position"), NULL);
}
