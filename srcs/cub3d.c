/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 01:43:15 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/04 20:12:30 by momox            ###   ########.fr       */
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
	load_masks(&data, data.assets);
	loops(&data);
	free_n_exit(&data, 0);
}
