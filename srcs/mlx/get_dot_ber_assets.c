/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dot_ber_assets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:43:32 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/17 21:15:27 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_image_t	*extract_img(t_game *data, char *path)
{
	mlx_image_t		*img;

	while (*path == ' ')
		path++;
	img = asset_to_image(data, path);
	return (img);
}

uint32_t	extract_color(char **color)
{
	return (create_trgb(255,
			(unsigned char)ft_atoi_mod(color[0]),
			(unsigned char)ft_atoi_mod(color[1]),
			(unsigned char)ft_atoi_mod(color[2])));
}

void	get_dot_ber_assets(t_game *data, t_assets *assets,
	t_parsing *parsing)
{
	assets->north_img = extract_img(data, parsing->north_path);
	assets->south_img = extract_img(data, parsing->south_path);
	assets->west_img = extract_img(data, parsing->west_path);
	assets->east_img = extract_img(data, parsing->east_path);
	assets->floor_trgb = extract_color(parsing->floor_rgb);
	assets->ceiling_trgb = extract_color(parsing->ceiling_rgb);
}
