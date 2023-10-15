/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:41:18 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/12 19:28:55 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_player_x(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
				return (x);
		}
	}
	return (0);
}

int	find_player_y(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
				return (y);
		}
	}
	return (0);
}

char	**map_w_null_background(t_list **x_chain, char **map)
{
	int		i;
	char	**new;
	int		max_len;

	new = x_malloc(x_chain, sizeof(char *) * (ft_tablen(map) + 3));
	max_len = 0;
	i = -1;
	while (map[++i])
		if (ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
	i = -1;
	while (++i < ft_tablen(map) + 2)
		new[i] = x_malloc(x_chain, sizeof(char) * (max_len + 3));
	new[i] = NULL;
	i = -1;
	while (map[++i])
		ft_strncpy(&new[i + 1][1], map[i], ft_strlen(map[i]));
	return (new);
}

void	valid_way(t_game_data *data, char **map, int x, int y)
{
	if (map[y][x] == '\0' || map[y][x] == ' ')
		exit_error(data, "map not closed");
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	valid_way(data, map, (x + 1), y);
	valid_way(data, map, (x - 1), y);
	valid_way(data, map, x, (y + 1));
	valid_way(data, map, x, (y - 1));
}
