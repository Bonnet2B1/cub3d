/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:43:32 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/15 15:51:30 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_image_t	*extract_img(t_game_data *data, char *path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	while (*path == ' ')
		path++;
	texture = mlx_load_png(path);
	if (!texture)
		exit_error(data, "invalid path to texture");
	img = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

int	extract_color(char **color)
{
	return (create_trgb(OPAQUE,
			(unsigned char)ft_atoi_mod(color[0]),
			(unsigned char)ft_atoi_mod(color[1]),
			(unsigned char)ft_atoi_mod(color[2])));
}

t_assets	*get_assets(t_game_data *data, t_parsing *parsing)
{
	t_assets	*assets;

	assets = assets_init(data);
	assets->north_img = extract_img(data, parsing->north_path);
	assets->south_img = extract_img(data, parsing->south_path);
	assets->west_img = extract_img(data, parsing->west_path);
	assets->east_img = extract_img(data, parsing->east_path);
	assets->floor_trgb = extract_color(parsing->floor_rgb);
	assets->ceiling_trgb = extract_color(parsing->ceiling_rgb);
	return (assets);
}
