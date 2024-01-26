/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deg_to_rad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:09:34 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/25 20:32:10 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_deg_to_rad(double deg) // - corriger cette fonction pour qu'elle respecte la valeur principale d'un angle en radian lors de la conversion.
{
	double rad;

	rad = deg * M_PI / 180;
	if (rad >= 2 * M_PI)
		return (rad -= 2 * M_PI);
	else if (rad < 0)
		return (rad += 2 * M_PI);
	return (rad);
}
