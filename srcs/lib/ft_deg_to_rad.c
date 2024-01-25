/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deg_to_rad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:09:34 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/25 20:15:44 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_deg_to_rad(double deg) // - corriger cette fonction pour qu'elle respecte la valeur principale d'un angle en radian lors de la conversion.
{
	return (deg * M_PI / 180);
}
