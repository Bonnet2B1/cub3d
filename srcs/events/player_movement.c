/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:27:01 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/26 19:00:24 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (is_collision(data->gps, (int)floor(player->y + STEP_LEN * sin(player->angle)), (int)floor(player->x + STEP_LEN * cos(player->angle))))
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
	if (is_collision(data->gps, (int)floor(player->y + STEP_LEN * sin(get_principal_measure(player->angle + M_PI))), (int)floor(player->x + STEP_LEN * cos(get_principal_measure(player->angle + M_PI)))))
		return ;
	player->y += (STEP_LEN * sin(get_principal_measure(player->angle + M_PI)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(get_principal_measure(player->angle + M_PI)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_left(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (is_collision(data->gps, (int)floor(player->y + STEP_LEN * sin(get_principal_measure(player->angle - M_PI/2))), (int)floor(player->x + STEP_LEN * cos(get_principal_measure(player->angle - M_PI/2)))))
		return ;
	player->y += (STEP_LEN * sin(get_principal_measure(player->angle - M_PI / 2)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(get_principal_measure(player->angle - M_PI / 2)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_right(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (is_collision(data->gps, (int)floor(player->y + STEP_LEN * sin(get_principal_measure(player->angle + M_PI/2))), (int)floor(player->x + STEP_LEN * cos(get_principal_measure(player->angle + M_PI/2)))))
		return ;
	player->y += (STEP_LEN * sin(get_principal_measure(player->angle + M_PI / 2)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(get_principal_measure(player->angle + M_PI / 2)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}
