#include "../includes/so_long.h"

int	chk_collect(t_data *data)
{
	int		i;
	int		y;
	int		count;

	i = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collect)
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);
}

int	end(t_data *data)
{
	int		i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
		mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	//mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->mlx_ptr);
	exit(0);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == 53)
		end(data);
	if (keysym == 13 || keysym == 126)
		render_top(data);
	if (keysym == 2 || keysym == 124)
		render_right(data);
	if (keysym == 0 || keysym == 123)
		render_left(data);
	if (keysym == 1 || keysym == 125)
		render_down(data);
	return (0);
}
