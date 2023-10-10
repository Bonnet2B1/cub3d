/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:43:50 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/11 00:07:41 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_file(t_game_data *data, char *file)
{
	int		fd;
	char	buf[1];

	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		exit_error(&data->x_chain, "wrong file extension");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(&data->x_chain, "file not found");
	if (read(fd, buf, 1) <= 0)
		return (close(fd), exit_error(&data->x_chain, "file is empty"));
	close(fd);
}
