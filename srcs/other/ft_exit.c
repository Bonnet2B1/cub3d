/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:08:11 by edelarbr          #+#    #+#             */
/*   Updated: 2023/10/10 02:49:16 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_error(t_game_data *data, char *message)
{
	if (data)
		x_free(&data->malloc_chain);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}
