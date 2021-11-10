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
//			if (j == x || i == y)
//				img_pix_put(data->img, j, i, BLUE);
//			else
				img_pix_put(data->img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}

int take_pix(int x, int y, t_text *text)
{
	unsigned int 	color;
	unsigned int	*addr_int;

	addr_int = (unsigned int *)text->addr;
	color = *(addr_int + y * (text->line_len / 4) + x);

	return (color);
}

int render_text(t_data *data, int x, int y, t_text *text)
{
	int i;
	int j;
	int	color;
	
	i = 0;
	while (i < CELL_WIDTH)
	{
		j = 0;
		while (j < CELL_WIDTH)
		{
			color = take_pix(j * text->width / CELL_WIDTH, i * text->height / CELL_WIDTH, text);
			img_pix_put(data->img, x * CELL_WIDTH + j, y * CELL_WIDTH + i, color);
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
				render_text(data, j, i, data->text_wall);
//				render_cell(data, j, i, RED);
			if (data->scene->map[i][j] == EMPTY || data->scene->map[i][j] == SPRITE
				|| data->scene->map[i][j] == PLAYER)
				render_text(data, j, i, data->text_empty);
//				render_cell(data, j, i, GREEN);
			if (data->scene->map[i][j] == SPRITE)
				render_text(data, j, i, data->text_sprite);
//				render_cell(data, j, i, BLUE);
			if (data->scene->map[i][j] == EXIT)
				render_text(data, j, i, data->text_exit);
//				render_cell(data, j, i, BLACK);
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

	x = data->player->x * CELL_WIDTH;
	y = data->player->y * CELL_WIDTH;
	i = y;
	while (i < y + CELL_WIDTH)
	{
		j = x;
		while (j < x + CELL_WIDTH)
		{
			img_pix_put(data->img, j, i, 0x878787);
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
	render_background(data, BLACK);
	render_map(data);
//	render_player(data);
	render_text(data, data->player->x, data->player->y, data->text_player);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
	debug_info(data);
	return (0);
}

int texture_init(t_data *data, t_text *texture, char *path)
{
//	free and destroy in case of error	
	texture->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &texture->width, &texture->height);
	if (texture->mlx_img == NULL)
		return (1);
	texture->addr = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->line_len, &texture->endian);
	if (texture->addr == NULL)
		return (1);
	return (0);
}

int render_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->scene->win_width, data->scene->win_height, "SNAKE EATER");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (1);
	}
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, data->scene->win_width, data->scene->win_height);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, 
		&data->img->line_len, &data->img->endian);
	texture_init(data, data->text_player, "srcs/textures/snake.xpm");
	texture_init(data, data->text_empty, "srcs/textures/empty-2.xpm");
	texture_init(data, data->text_wall, "srcs/textures/wall-1.xpm");
	texture_init(data, data->text_sprite, "srcs/textures/collectible-1.xpm");
	texture_init(data, data->text_exit, "srcs/textures/exit-1.xpm");
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask, close_window, data);
	mlx_loop(data->mlx_ptr);
	clean_render(data);
	return (0);
}