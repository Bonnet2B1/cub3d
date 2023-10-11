/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:40:17 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/12 00:13:59 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*extract_map(t_game_data *data, t_parsing *parsing, int i)
{
	t_map	*gps;

	while (parsing->file[i] && ft_strncmp(parsing->file[i], "", 1) == 0)
		i++;
	gps = map_init(data);
	gps->map = &parsing->file[i];
	if (!gps->map[0])
		exit_error(&data->x_chain, "there is no map");
	while (gps->map[++gps->height])
	{
		if (ft_strlen(gps->map[gps->height]) > gps->width)
			gps->width = ft_strlen(gps->map[gps->height]);
	}
	print_map(gps->map);
	return (gps);
}

char	*get_object(t_game_data *data, char *search, char **tab, int *i)
{
	char	*object;
	int		j;

	j = 0;
	while (tab[*i] && ft_strncmp(tab[*i], "", 1) == 0)
		(*i)++;
	while (tab[*i][j] && search[j] && tab[*i][j] == search[j])
		j++;
	if (j != ft_strlen(search))
		exit_error(&data->x_chain, FILE_FORMAT);
	object = ft_strdup(&data->x_chain, &tab[(*i)++][j]);
	return (object);
}

void	extract_assets_lines(t_game_data *data, t_parsing *parsing, int *i)
{
	parsing->north_path = get_object(data, "NO ", parsing->file, i);
	parsing->south_path = get_object(data, "SO ", parsing->file, i);
	parsing->west_path = get_object(data, "WE ", parsing->file, i);
	parsing->east_path = get_object(data, "EA ", parsing->file, i);
	parsing->floor_color = get_object(data, "F ", parsing->file, i);
	parsing->ceiling_color = get_object(data, "C ", parsing->file, i);
}

t_map	*extract_data(t_game_data *data, t_parsing *parsing)
{
	int		i;
	t_map	*gps;

	i = 0;
	extract_assets_lines(data, parsing, &i);
	gps = extract_map(data, parsing, i);
	return (gps);
}
