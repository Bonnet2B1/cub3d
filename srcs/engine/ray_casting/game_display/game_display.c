/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:34:25 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/28 21:37:43 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

void	put_floor_and_ceiling(t_game_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_HEIGHT / 2)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			mlx_put_pixel(data->big_mask, j, i, 0x0000FFFF);
	}
	while (i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			mlx_put_pixel(data->big_mask, j, i, 0x00FF00FF);
		i++;
	}
}


void put_line(mlx_image_t *big_mask, t_ray *ray, int ray_idx, uint32_t color) // ! c'est (trop) brouillon mais ça marche (jsp encore trop pourquoi)
{
	int line_height;
	int first_pixel;
	int last_pixel;
	int	i;

	line_height = (WINDOW_WIDTH)/(ray->len);
	first_pixel = (WINDOW_HEIGHT - line_height) / 2;
	last_pixel = WINDOW_HEIGHT - first_pixel;
	i = first_pixel;
	if (i < 0)
		i = 0;
	while (i < last_pixel)
	{
		if (i > WINDOW_HEIGHT - 1)
			break ;
		mlx_put_pixel(big_mask, ray_idx, i, color);
		i++;
	}
}

void	put_wall(t_game_data *data, t_ray *ray, int ray_idx)
{
	if (ray->side == 'N')
	{
		put_line(data->big_mask, ray, ray_idx, 0xFF69B4FF);
	}
	if (ray->side == 'S')
	{
		put_line(data->big_mask, ray, ray_idx, 0xC2FFF5FF);
	}
	if (ray->side == 'E')
	{
		put_line(data->big_mask, ray, ray_idx, 0xFFA500FF);

	}
	if (ray->side == 'W')
	{
		put_line(data->big_mask, ray, ray_idx, 0xFFD700FF);
	}
}

void	put_assets(t_game_data *data, t_ray *ray, char **map)
{
	int	ray_idx;

	ray_idx = -1;
	while (++ray_idx < WINDOW_WIDTH)
	{
		// ray[ray_idx].len *= cos(get_principal_measure(data->player->angle - ray[ray_idx].angle)); // * fix fish eye (essaye de l'enlever mdr)
		if (map[ray->map_y][ray->map_x] == '1') // * si le rayon tombe sur un mur
			put_wall(data, &ray[ray_idx], ray_idx); // * on une ligne verticale de mur
		else // ! tous les rayons devraient finir par tomber sur un mur
		{
			printf("\nBITE!\n");
			printf("map[%d][%d] = %c\n", ray->map_y, ray->map_x, map[ray->map_y][ray->map_x]);
			printf("horizontal->len = %f\n", ray[ray_idx].horizontal->len);
			printf("vertical->len = %f\n", ray[ray_idx].vertical->len);
			printf("len = %f\n", ray[ray_idx].len); // ! comparer la len finale avec la len de la verticale et de l'horizontale pour savoir d'où vient l'erreur (ici c'est l'horizontale)
			printf("angle = %f\n", ray[ray_idx].angle); // ! l'erreur vient seulement en en regardant en haut à gauche
			// ! le problème vient probablement de looking_left_up_h()
			// ! looking_right_up(h?) aussi
			/* BITE!
			map[5][10] = 0
			horizontal->len = 8.128225
			vertical->len = 8.556722
			len = 7.039250
			angle = 5.565988 */ // ! NOUVEAU PROBLEME
		}
		// else if (ray[ray_idx].type == 'C')
		// 	put_closed_door(data, &ray[ray_idx]);
	}
}

void	game_display(t_game_data *data)
{
	(void)data;
	put_floor_and_ceiling(data);
	put_assets(data, data->player->ray, data->gps->map);
}

