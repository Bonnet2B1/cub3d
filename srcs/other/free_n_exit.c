/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:24:14 by edelarbr          #+#    #+#             */
/*   Updated: 2024/02/05 19:14:47 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	del_all_imgs_three(t_game *data)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (data->assets->dancing_ra_imgs[i])
			mlx_delete_image(data->mlx, data->assets->dancing_ra_imgs[i]);
	if (data->assets->textures_mask)
		mlx_delete_image(data->mlx, data->assets->textures_mask);
	if (data->assets->darkness_textures_mask)
		mlx_delete_image(data->mlx, data->assets->darkness_textures_mask);
	if (data->assets->vignette_mask)
		mlx_delete_image(data->mlx, data->assets->vignette_mask);
	if (data->assets->collapse_img)
		mlx_delete_image(data->mlx, data->assets->collapse_img);
}

void	del_all_imgs_two(t_game *data)
{
	if (data->assets->anubis_not_happy_img)
		mlx_delete_image(data->mlx, data->assets->anubis_not_happy_img);
	if (data->assets->basic_wall_img)
		mlx_delete_image(data->mlx, data->assets->basic_wall_img);
	if (data->assets->door_img)
		mlx_delete_image(data->mlx, data->assets->door_img);
	if (data->assets->goal_img)
		mlx_delete_image(data->mlx, data->assets->goal_img);
	if (data->assets->mummy_left_img)
		mlx_delete_image(data->mlx, data->assets->mummy_left_img);
	if (data->assets->mummy_right_img)
		mlx_delete_image(data->mlx, data->assets->mummy_right_img);
	if (data->assets->peacock_img)
		mlx_delete_image(data->mlx, data->assets->peacock_img);
	if (data->assets->pillar_img)
		mlx_delete_image(data->mlx, data->assets->pillar_img);
	if (data->assets->sarcophagus_img)
		mlx_delete_image(data->mlx, data->assets->sarcophagus_img);
	if (data->assets->wall_w_hole_img)
		mlx_delete_image(data->mlx, data->assets->wall_w_hole_img);
	if (data->assets->background_mask)
		mlx_delete_image(data->mlx, data->assets->background_mask);
	if (data->assets->darkness_background_mask)
		mlx_delete_image(data->mlx, data->assets->darkness_background_mask);
	del_all_imgs_three(data);
}

void	del_all_imgs(t_game *data)
{
	int	i;

	i = -1;
	while (++i < WINDOW_WIDTH)
		if (data->player && data->player->ray[i]
			&& data->player->ray[i]->ray_img)
			mlx_delete_image(data->mlx, data->player->ray[i]->ray_img);
	if (data->assets->north_img)
		mlx_delete_image(data->mlx, data->assets->north_img);
	if (data->assets->south_img)
		mlx_delete_image(data->mlx, data->assets->south_img);
	if (data->assets->west_img)
		mlx_delete_image(data->mlx, data->assets->west_img);
	if (data->assets->east_img)
		mlx_delete_image(data->mlx, data->assets->east_img);
	if (data->assets->minimap_wall_img)
		mlx_delete_image(data->mlx, data->assets->minimap_wall_img);
	if (data->assets->minimap_door_img)
		mlx_delete_image(data->mlx, data->assets->minimap_door_img);
	if (data->assets->minimap_goal_img)
		mlx_delete_image(data->mlx, data->assets->minimap_goal_img);
	if (data->assets->anubis_chill_img)
		mlx_delete_image(data->mlx, data->assets->anubis_chill_img);
	del_all_imgs_two(data);
}

void	free_n_exit(t_game *data, int exit_code)
{
	// if (data->assets)
	// 	del_all_imgs(data);
	if (data->mlx)
		mlx_terminate(data->mlx);
	x_free(&data->x_chain);
	exit(exit_code);
}
