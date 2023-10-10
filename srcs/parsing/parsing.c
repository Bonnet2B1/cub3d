/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:15:45 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/10 14:22:53 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	valid_file(t_game_data *data, char *file)
{
	int		fd;
	char	buf[1];
	char	*file_one_line;

	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		exit_error(data, "wrong file extension");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(data, "file not found");
	if (read(fd, buf, 1) <= 0)
		return (close(fd), exit_error(data, "file is empty"));
	close(fd);
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1) <= 0)
		file_one_line = ft_strjoin(file_one_line, buf);
}

void	parsing(t_game_data *data, int argc, char **argv)
{
	if (argc < 2)
		exit_error(data, "map needed");
	if (argc > 2)
		exit_error(data, "too many arguments");
	valid_file(data, argv[1]);
}
