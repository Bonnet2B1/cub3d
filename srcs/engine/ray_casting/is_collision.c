/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:41:06 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/20 17:04:30 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_collision(t_map *gps, int y, int x)
{
	if (x < 0 || y < 0 || x > gps->width - 1|| y > gps->height - 1)
		return (1);
	printf("map[%d][%d] = ", y, x);
	printf("%c\n", gps->map[y][x]);
	if (gps->map[y][x] == '0')
		return (0);
	return (1);
}
