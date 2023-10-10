/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file_to_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:43:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/10 20:19:07 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**extract_file_to_tab(t_game_data *data, char *file)
{
	int		fd;
	char	buf[2];
	char	*file_one_line;

	fd = open(file, O_RDONLY);
	buf [1] = '\0';
	file_one_line = NULL;
	while (read(fd, buf, 1) == 1)
	{
		file_one_line = ft_strjoin(&data->x_chain, file_one_line, buf);
	}
	close(fd);
	return (ft_split(&data->x_chain, file_one_line, '\n'));
}
