/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:27:01 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/30 15:43:17 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_game *data)
{
	t_player	*player;

	player = data->player;
	if (is_collision(data->gps, (int)floor(player->y + STEP_LEN * sin(player->angle)), (int)floor(player->x + STEP_LEN * cos(player->angle))))
		return ;
	player->front->angle = player->angle;
	deep_ray_cpy(player->front);
	player->front->len = get_len(data, player->front);
	if (STEP_LEN >= player->front->len)
		return ;
	player->y += (STEP_LEN * sin(player->angle));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(player->angle));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_backward(t_game *data)
{
	t_player	*player;

	player = data->player;
	if (is_collision(data->gps, (int)floor(player->y + STEP_LEN * sin(get_principal_measure(player->angle + M_PI))), (int)floor(player->x + STEP_LEN * cos(get_principal_measure(player->angle + M_PI)))))
		return ;
	player->back->angle = get_principal_measure(player->angle - M_PI);
	deep_ray_cpy(player->back);
	player->back->len = get_len(data, player->back);
	if (STEP_LEN >= player->back->len)
		return ;
	player->y += (STEP_LEN * sin(get_principal_measure(player->angle + M_PI)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(get_principal_measure(player->angle + M_PI)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_left(t_game *data)
{
	t_player	*player;

	player = data->player;
	if (is_collision(data->gps, (int)floor(player->y + STEP_LEN * sin(get_principal_measure(player->angle - M_PI/2))), (int)floor(player->x + STEP_LEN * cos(get_principal_measure(player->angle - M_PI/2)))))
		return ;
	player->left->angle = get_principal_measure(player->angle - M_PI / 2);
	deep_ray_cpy(player->left);
	player->left->len = get_len(data, player->left);
	if (STEP_LEN >= player->left->len)
		return ;
	player->y += (STEP_LEN * sin(get_principal_measure(player->angle - M_PI / 2)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(get_principal_measure(player->angle - M_PI / 2)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_right(t_game *data)
{
	t_player	*player;

	player = data->player;
	if (is_collision(data->gps, (int)floor(player->y + STEP_LEN * sin(get_principal_measure(player->angle + M_PI/2))), (int)floor(player->x + STEP_LEN * cos(get_principal_measure(player->angle + M_PI/2)))))
		return ;
	player->left->angle = get_principal_measure(player->angle + M_PI / 2);
	deep_ray_cpy(player->right);
	player->right->len = get_len(data, player->right);
	if (STEP_LEN >= player->right->len)
		return ;
	player->y += (STEP_LEN * sin(get_principal_measure(player->angle + M_PI / 2)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (STEP_LEN * cos(get_principal_measure(player->angle + M_PI / 2)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}
