/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_principal_measure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:50:21 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/26 19:00:24 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_principal_measure(double angle)
{
	if (angle >= 2 * M_PI)
		return (angle -= 2 * M_PI);
	else if (angle < 0)
		return (angle += 2 * M_PI);
	return (angle);
}
