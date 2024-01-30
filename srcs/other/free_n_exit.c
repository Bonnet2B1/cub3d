/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:24:14 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/15 15:50:06 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rm_mlx_leaks(t_game *data)
{
	if (data->assets->north_img)
		mlx_delete_image(data->mlx, data->assets->north_img);
	if (data->assets->south_img)
		mlx_delete_image(data->mlx, data->assets->south_img);
	if (data->assets->west_img)
		mlx_delete_image(data->mlx, data->assets->west_img);
	if (data->assets->east_img)
		mlx_delete_image(data->mlx, data->assets->east_img);
}

void	free_n_exit(t_game *data, int exit_code)
{
	if (data->assets)
		rm_mlx_leaks(data);
	x_free(&data->x_chain);
	if (data->mlx)
		mlx_terminate(data->mlx);
	exit(exit_code);
}
