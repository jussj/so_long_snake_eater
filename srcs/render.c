/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:38:10 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/17 16:44:33 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (data->scene->map[i][j] == EMPTY || data->scene->map[i][j] == SPRITE
				|| data->scene->map[i][j] == PLAYER)
				render_text(data, j, i, data->text_empty);
			if (data->scene->map[i][j] == SPRITE)
				render_text(data, j, i, data->text_sprite);
			if (data->scene->map[i][j] == EXIT)
				render_text(data, j, i, data->text_exit);
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
	render_text(data, data->player->x, data->player->y, data->text_player);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
// PRINT DEBUG INFOS
	debug_info(data);
	return (0);
}

int render_init(t_data *data)
{
//	DOUBLE CHECK FREE/DESTROY IN CASE OF RETURN 1
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(exit_error(data, "MLX initialization failed", 0));
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->scene->win_width, 
		data->scene->win_height, "./so_long");
	if (data->win_ptr == NULL)
		exit(exit_error(data, "MLX initialization failed", 0));
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, data->scene->win_width, 
		data->scene->win_height);
	if (data->img->mlx_img == NULL)
		exit(exit_error(data, "MLX initialization failed", 0));
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, 
		&data->img->line_len, &data->img->endian);
	if (data->img->addr == NULL)
		exit(exit_error(data, "MLX initialization failed", 0));
	load_all_textures(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask, close_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

