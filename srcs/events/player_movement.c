/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:27:01 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/31 17:23:54 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_game *data)
{
	t_player	*player;

	player = data->player;
	player->front->angle = player->angle;
	deep_ray_cpy(player->front);
	player->front->len = get_len(data, player->front);
	if (player->step_len >= player->front->len)
		return ;
	player->y += (player->step_len * sin(player->angle));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (player->step_len * cos(player->angle));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_backward(t_game *data)
{
	t_player	*player;

	player = data->player;
	player->back->angle = get_principal_measure(player->angle - M_PI);
	deep_ray_cpy(player->back);
	player->back->len = get_len(data, player->back);
	if (player->step_len >= player->back->len)
		return ;
	player->y += (player->step_len * sin(get_principal_measure(player->angle + M_PI)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (player->step_len * cos(get_principal_measure(player->angle + M_PI)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_left(t_game *data)
{
	t_player	*player;

	player = data->player;
	player->left->angle = get_principal_measure(player->angle - M_PI / 2);
	deep_ray_cpy(player->left);
	player->left->len = get_len(data, player->left);
	if (player->step_len >= player->left->len)
		return ;
	player->y += (player->step_len * sin(get_principal_measure(player->left->angle)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (player->step_len * cos(get_principal_measure(player->left->angle)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_right(t_game *data)
{
	t_player	*player;

	player = data->player;
	player->right->angle = get_principal_measure(player->angle + M_PI / 2);
	deep_ray_cpy(player->right);
	player->right->len = get_len(data, player->right);
	if (player->step_len >= player->right->len)
		return ;
	player->y += (player->step_len * sin(get_principal_measure(player->right->angle)));
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
	player->x += (player->step_len * cos(get_principal_measure(player->right->angle)));
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}
