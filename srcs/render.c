#include "so_long.h"

void img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}


int render_background(t_data *data, int color)
{
	int i;
	int j;

	i = 0;
	while (i < data->scene->win_height)
	{
		j = 0;
		while (j < data->scene->win_width)
			img_pix_put(data->img, j++, i, color);
		i++;
	}
	return (0);	
}

int render_cell(t_data *data, double x, double y, int color)
{
	int i;
	int j;
	
	x *= CELL_WIDTH;
	y *= CELL_WIDTH;
	i = y;
	while (i < y + CELL_WIDTH)
	{
		j = x;
		while (j < x + CELL_WIDTH)
		{
			if (j == x || i == y)
				img_pix_put(data->img, j, i, BLUE);
			else
				img_pix_put(data->img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}

int render_map(t_data *data)
{
	int 	i;
	int 	j;

	i = 0;
	while (data->scene->map[i])
	{
		j = 0;
		while (data->scene->map[i][j])
		{
			if (data->scene->map[i][j] == WALL)
				render_cell(data, j, i, RED);
			if (data->scene->map[i][j] == EMPTY || data->scene->map[i][j] == PLAYER)
				render_cell(data, j, i, GREEN);
			j++;				
		}
		i++;
	}
	return (0);
}

int	render_player(t_data *data)
{
	int i;
	int j;
	int x;
	int y;

	x = data->player->x * CELL_WIDTH + CELL_WIDTH / 4;
	y = data->player->y * CELL_WIDTH + CELL_WIDTH / 4;
	i = y;
//	render_angle(data, BLACK, 20);
	while (i < y + CELL_WIDTH / 2)
	{
		j = x;
		while (j < x + CELL_WIDTH / 2)
		{
			img_pix_put(data->img, j, i, BLACK);
			j++;
		}
		i++;
	}
	return (0);
}


int render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(data, BLUE);
	render_map(data);
	render_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
	return (0);
}

int render_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->scene->win_width, data->scene->win_height, "cub2d");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (1);
	}
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, data->scene->win_width, data->scene->win_height);
	printf("OK\n");
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, 
		&data->img->line_len, &data->img->endian);	
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask, close_window, data);
	
	mlx_loop(data->mlx_ptr);

	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}