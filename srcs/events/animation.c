#include "../cub3d.h"

void	animation(void *param)
{
	t_game	*data;
	int		couldown;

	data = (t_game *)param;
	couldown = 0;
	while (couldown < ANIMATION_SPEED)
		couldown++;
	data->assets->frame++;
	if (data->assets->frame > 12)
		data->assets->frame = 0;
}
