/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:27:01 by edelarbr          #+#    #+#             */
/*   Updated: 2023/12/28 20:45:49 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->gps->map[(int)(player->y - STEP_LEN)][(int)player->x] == '1') // - '- STEP_LEN' à modifier lorqu'on prendra en compte l'angle de rotation du joueur
		return ;
	player->y -= STEP_LEN;
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
}

void	move_backward(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->gps->map[(int)(player->y + STEP_LEN)][(int)player->x] == '1') // - '+ STEP_LEN' à modifier lorqu'on prendra en compte l'angle de rotation du joueur
		return ;
	player->y += STEP_LEN;
	player->minimap_img->instances[0].y
		= player->y * data->gps->minimap_img_size;
}

void	move_left(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->gps->map[(int)player->y][(int)(player->x - STEP_LEN)] == '1') // - '- STEP_LEN' à modifier lorqu'on prendra en compte l'angle de rotation du joueur
		return ;
	player->x -= STEP_LEN;
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

void	move_right(t_game_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->gps->map[(int)(player->y)][(int)(player->x + STEP_LEN)] == '1') // - '+ STEP_LEN' à modifier lorqu'on prendra en compte l'angle de rotation du joueur
		return ;
	player->x += STEP_LEN;
	player->minimap_img->instances[0].x
		= player->x * data->gps->minimap_img_size;
}

// void	player_movement(t_game_data *data, int delta_x, int delta_y)
// {
// 	double	player_step;
// 	int		wanted_x;
// 	int		wanted_y;

// 	player_step = 0.1;
// 	wanted_x = data->gps->px + delta_x * player_step;
// 	wanted_y = data->gps->py + delta_y * player_step;
// 	if (wanted_x > 0 && data->gps->map[wanted_y][wanted_x + 1] == '1')
// 		return ;
// 	else if (wanted_y > 0 && data->gps->map[wanted_y + 1][wanted_x] == '1')
// 		return ;
// 	else if (data->gps->map[wanted_y][wanted_x] == '1')
// 		return ;
// 	data->gps->py += player_step * delta_y;
// 	data->gps->px += player_step * delta_x;
// 	// printf("Going in %f, %f (%d, %d)\n", data->gps->px, data->gps->py,
// 	// 	(int)data->gps->px, (int)data->gps->py);
// 	data->assets->minimap_player_img->instances[0].y
// 		= data->gps->py * data->gps->minimap_img_size;
// 	data->assets->minimap_player_img->instances[0].x
// 		= data->gps->px * data->gps->minimap_img_size;
// }
