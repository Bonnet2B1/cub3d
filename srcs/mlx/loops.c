/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:54 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/18 21:52:30 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	loops(t_game *data)
{
	mlx_loop_hook(data->mlx, keyboard, data);
	mlx_loop_hook(data->mlx, ray_casting, data);
	mlx_loop(data->mlx);
}
