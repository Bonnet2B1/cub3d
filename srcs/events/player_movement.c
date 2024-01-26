/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:27:01 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/26 15:21:44 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->gps->map[(int)(player->y + STEP_LEN * sin(player->angle))][(int)(player->x + STEP_LEN * sin(player->angle))] != '0')
		return ;
	player->y += (STEP_LEN * sin(player->angle));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(player->angle));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_backward(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->gps->map[(int)(player->y + STEP_LEN * sin(get_principal_measure(player->angle + PI)))][(int)(player->x + STEP_LEN * sin(get_principal_measure(player->angle + PI)))] != '0')
		return ;
	player->y += (STEP_LEN * sin(get_principal_measure(player->angle + PI)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(get_principal_measure(player->angle + PI)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_left(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->gps->map[(int)(player->y + STEP_LEN * sin(get_principal_measure(player->angle - PI / 2)))][(int)(player->x + STEP_LEN * sin(get_principal_measure(player->angle - PI / 2)))] != '0')
		return ;
	player->y += (STEP_LEN * sin(get_principal_measure(player->angle - PI / 2)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(get_principal_measure(player->angle - PI / 2)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_right(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->gps->map[(int)(player->y + STEP_LEN * sin(get_principal_measure(player->angle + PI / 2)))][(int)(player->x + STEP_LEN * sin(get_principal_measure(player->angle + PI / 2)))] != '0')
		return ;
	player->y += (STEP_LEN * sin(get_principal_measure(player->angle + PI / 2)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(get_principal_measure(player->angle + PI / 2)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}
