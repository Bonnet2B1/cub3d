/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:39:46 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/03 16:34:44 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
				&& map[i][j] != ' ' && map[i][j] != '2')
				exit_error(data, "unauthorized character in map");
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				player++;
		}
	}
	if (player < 1)
		exit_error(data, "no player in map");
	if (player > 1)
		exit_error(data, "too many players in map");
}
