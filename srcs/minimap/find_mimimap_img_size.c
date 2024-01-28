/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mimimap_img_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:56:14 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/02 13:59:08 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_mimimap_img_size(int width, int height)
{
	if (MINIMAP_ASSET_SIZE > 0)
		return (MINIMAP_ASSET_SIZE);
	if (width > height)
		return ((WINDOW_WIDTH / 5) / width);
	else
		return ((WINDOW_WIDTH / 5) / height);
}
