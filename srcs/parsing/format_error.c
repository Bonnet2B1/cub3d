/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:40:42 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/12 19:28:12 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	format_error(t_game_data *data, t_parsing *parsing)
{
	if (!parsing->file[0] || ft_strncmp(parsing->file[0], "NO ", 3) != 0
		|| !parsing->file[1] || ft_strncmp(parsing->file[1], "SO ", 3) != 0
		|| !parsing->file[2] || ft_strncmp(parsing->file[2], "WE ", 3) != 0
		|| !parsing->file[3] || ft_strncmp(parsing->file[3], "EA ", 3) != 0
		|| !parsing->file[4] || ft_strncmp(parsing->file[4], "F ", 2) != 0
		|| !parsing->file[5] || ft_strncmp(parsing->file[5], "C ", 2) != 0)
		exit_error(data, FILE_FORMAT);
	if (!parsing->file[6])
		exit_error(data, "there is no map");
}
