#include "../cub3d.h"

void	animation(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	data->assets->frame++;
	if (data->assets->frame > ANIMATION_SPEED)
		data->assets->frame = 0;
}
