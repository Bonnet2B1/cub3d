/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:25:08 by edelarbr          #+#    #+#             */
/*   Updated: 2024/01/31 17:29:00 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_beyond_the_wall(t_game *data, t_map *gps, t_ray *ray)
{
	(void)data;
	if (ray->map_x >= 0 && ray->map_y >= 0 && ray->map_x < gps->width && ray->map_y < gps->height)
		ray->type = gps->map[ray->map_y][ray->map_x];
	else
	{
		printf("map_x: %d\n", ray->map_x);
		printf("map_y: %d\n", ray->map_y);
		printf("gps->width: %d\n", gps->width);
		printf("gps->height: %d\n", gps->height);
		exit_error(data, "AddressSanitizer:DEADLYSIGNAL\n=================================================================\n==12274==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000008 (pc 0x00010482f800 bp 0x00016b5eebe0 sp 0x00016b5eeb90 T0)\n==12274==The signal is caused by a READ memory access.\n==12274==Hint: address points to the zero page.\n    #0 0x10482f800 in mlx_new_image+0x3c (cub3D:arm64+0x10001f800)\n    #1 0x10481ef78 in player_init init.c:78\n    #2 0x104822900 in parsing parsing.c:20\n    #3 0x104814508 in main cub3d.c:20\n    #4 0x18706d0dc  (<unknown module>)\n\n==12274==Register values:\n x[0] = 0x0000000000000000   x[1] = 0x0000000000000001   x[2] = 0x0000000000000001   x[3] = 0x00000001074057e8\n x[4] = 0x00000001074057e8   x[5] = 0x0000000000000001   x[6] = 0x000000016adf4000   x[7] = 0x0000000000000001\n x[8] = 0x00000000ffff8001   x[9] = 0x00000000ffff8001  x[10] = 0x00000001074057d0  x[11] = 0x000000700001ffff\nx[12] = 0x0000000000000000  x[13] = 0x55ec18e8f8682e18  x[14] = 0x0000000000007e01  x[15] = 0x0000000000000006\nx[16] = 0x00000001051a8ad8  x[17] = 0x00000001051e80b8  x[18] = 0x0000000000000000  x[19] = 0x000000016b5eefc0\nx[20] = 0x0000000000000001  x[21] = 0x000000016b5ef150  x[22] = 0x0000000000000001  x[23] = 0x000000016b5ef1d0\nx[24] = 0x000000016b5ef210  x[25] = 0x00000001870ec5eb  x[26] = 0x0000000000000000  x[27] = 0x0000000000000000\nx[28] = 0x0000000000000000     fp = 0x000000016b5eebe0     lr = 0x000000010481ef7c     sp = 0x000000016b5eeb90\nAddressSanitizer can not provide additional info.\nSUMMARY: AddressSanitizer: SEGV (cub3D:arm64+0x10001f800) in mlx_new_image+0x3c\n==12274==ABORTING\n[1]    12274 abort      ./cub3D big.cub");
	}
}

double	get_len(t_game *data, t_ray *ray)
{
	get_len_to_vertical_collision(data, ray->v);
	get_len_to_horizontal_collision(data, ray->h);
	if (ray->h->len < ray->v->len)
	{
		ray->op_x = ray->h->op_x;
		ray->op_y = ray->h->op_y;
		ray->map_x = ray->h->map_x;
		ray->map_y = ray->h->map_y;
		ray->sqrt_hit = ray->h->sqrt_hit;
		ray->side = ray->h->side;
		ray->type = ray->h->type;
		check_beyond_the_wall(data, data->gps, ray);
		return (ray->h->len);
	}
	else
	{
		ray->op_x = ray->v->op_x;
		ray->op_y = ray->v->op_y;
		ray->map_x = ray->v->map_x;
		ray->map_y = ray->v->map_y;
		ray->sqrt_hit = ray->v->sqrt_hit;
		ray->side = ray->v->side;
		check_beyond_the_wall(data, data->gps, ray);
		return (ray->v->len);
	}
}

void	deep_ray_cpy(t_ray *ray)
{
	ray->h->x = ray->x;
	ray->v->x = ray->x;
	ray->h->y = ray->y;
	ray->v->y = ray->y;
	ray->h->angle = ray->angle;
	ray->v->angle = ray->angle;
}

void	get_ray_data(t_game *data, t_player *player)
{
	int		i;
	double	first_ray_angle;

	first_ray_angle = get_principal_measure(data->player->angle - ft_deg_to_rad((float)FOV/2));
	i = -1;
	while (++i < WINDOW_WIDTH)
	{
		player->ray[i]->angle = get_principal_measure(first_ray_angle + i * ft_deg_to_rad((float)FOV/(WINDOW_WIDTH - 1)));
		deep_ray_cpy(player->ray[i]);
		player->ray[i]->len = get_len(data, player->ray[i]);
	}
	i = 0;
	while(i < WINDOW_WIDTH)
	{
		draw_lazer(data, data->player->ray[i]);
		i += 15;
	}
}

void	ray_casting(void *param)
{
	t_game	*data;

	data = param;
	get_ray_data(data, data->player);
	game_display(data);
}
