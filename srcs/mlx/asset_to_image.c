/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:40:31 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/06 19:14:12 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_image_t	*asset_to_image(t_game *data, char *path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		exit_error(data, "invalid path to texture");
	img = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}
