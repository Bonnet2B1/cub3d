/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:47:57 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/12 20:52:09 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	launch_mlx(t_game_data *data)
{
	data->mlx = mlx_init(
			data->gps->width * 64, data->gps->height * 64, "cub3D", false);
	data->assets = get_assets(data, data->parsing);
	mlx_loop(data->mlx);
}
