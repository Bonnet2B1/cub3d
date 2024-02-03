/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trgb_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:48:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/15 14:48:49 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

u_int32_t	create_rgbt(
	unsigned char r, unsigned char g, unsigned char b, unsigned char t)
{
	return (*(int *)(unsigned char [4]){t, b, g, r});
}
