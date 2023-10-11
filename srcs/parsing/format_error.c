/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:40:42 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/11 18:40:58 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	format_error(t_game_data *data, t_parsing *parsing)
{
	int	i;

	i = 0;
	if (ft_strncmp(parsing->file[i++], "NO ", 3) != 0
		|| ft_strncmp(parsing->file[i++], "SO ", 3) != 0
		|| ft_strncmp(parsing->file[i++], "WE ", 3) != 0
		|| ft_strncmp(parsing->file[i++], "EA ", 3) != 0
		|| ft_strncmp(parsing->file[i++], "", 1) != 0
		|| ft_strncmp(parsing->file[i++], "F ", 2) != 0
		|| ft_strncmp(parsing->file[i++], "C ", 2) != 0
		|| ft_strncmp(parsing->file[i++], "", 1) != 0
		|| !parsing->file[i++])
		exit_error(&data->x_chain, FILE_FORMAT);
}
