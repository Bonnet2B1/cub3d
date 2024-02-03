#include "../cub3d.h"

void	mouse_on_off(t_game *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_M))
		data->mouse = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_N))
		data->mouse = 0;
	if (data->mouse == 1)
	{
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
		mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
	else
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
}

void	mouse(void *param)
{
	t_game	*data;
	int	old_x;
	int	old_y;

	data = (t_game *)param;
	old_y = 0;
	old_x = WINDOW_WIDTH / 2;
	mlx_get_mouse_pos(data->mlx, &old_x, &old_y);
	mouse_on_off(data);
	if (data->mouse == 1)
	{
		if (old_x > WINDOW_WIDTH / 2)
		{
			rotate_right(data->player, MOUSE_SPEED * ((double)old_x -(WINDOW_WIDTH / 2)));
		}
		if (old_x < WINDOW_WIDTH / 2)
		{
			rotate_left(data->player, MOUSE_SPEED * ((double)(WINDOW_WIDTH / 2) - old_x));
		}
	}
}
