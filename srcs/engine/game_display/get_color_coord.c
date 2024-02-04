/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:20:16 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/30 19:22:48 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

u_int32_t	get_rgba_tex(u_int32_t color)
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
	u_int8_t	a;

	a = color >> 24;
	r = color >> 16;
	g = color >> 8;
	b = color;
	return (r << 8 | g << 16 | b << 24 | a << 0);
}

u_int32_t	get_color_coord(int x, int y, mlx_image_t *img)
{
	uint32_t	*pixel;
	u_int32_t	color;

	pixel = NULL;
	pixel = (uint32_t *)(img->pixels + (x + y * ASSET_SIZE) * sizeof(uint32_t));
	color = *pixel;
	return (get_rgba_tex(color));
	return (0);
}
