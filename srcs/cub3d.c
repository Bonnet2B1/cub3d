/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:43:15 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/27 17:45:02 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	data;

	data = game_data_init();
	data.map_name = argv[1];
	data.parsing = parsing(&data, argc, argv);
	load_assets(&data);
	create_minimap(&data, find_mimimap_img_size(data.gps->width,
			data.gps->height));
	loops(&data);
	free_n_exit(&data, 0);
}
