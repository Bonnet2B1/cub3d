/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:12:06 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/10 20:11:01 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_game_data	game_data_init(void)
{
	t_game_data	data;

	data.x_chain = NULL;
	return (data);
}

t_parsing	*parsing_init(t_game_data *data)
{
	t_parsing	*parsing;

	parsing = x_malloc(&data->x_chain, sizeof(t_parsing));
	if (!parsing)
		exit_error(data, "malloc error");
	return (parsing);
}
