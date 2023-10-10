/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:15:45 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/10 02:50:39 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parsing(t_game_data *data, int argc, char **argv)
{
	if (argc < 2)
		exit_error(data, "map needed");
	if (argc > 2)
		exit_error(data, "too many arguments");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
		exit_error(data, "wrong file extension");
}
