/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:54 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/02 17:24:38 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	loops(t_game_data *data)
{
	mlx_loop_hook(data->mlx, keyboard, data);
	mlx_loop_hook(data->mlx, ray_casting, data);
	mlx_loop(data->mlx);
}
