/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mimimap_img_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:56:14 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/17 22:04:27 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_mimimap_img_size(int width, int height)
{
	if (ASSET_SIZE > 0)
		return (ASSET_SIZE);
	if (width > height)
		return (200 / width);
	else
		return (200 / height);
}
