/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:08:11 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/12 19:27:21 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_error(t_game *data, char *message)
{
	ft_putstr_fd("Error\n", 2);
	if (message)
	{
		ft_putstr_fd("cub3d: ", 2);
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
	}
	free_n_exit(data, 1);
}
