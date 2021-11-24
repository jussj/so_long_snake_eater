/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:29:46 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/24 15:42:35 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*img_init(t_data *data)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(*img));
	if (img == NULL)
		exit(exit_error(data, "Memory allocation failed"));
	return (img);
}

t_text	*text_init(t_data *data)
{
	t_text	*text;

	text = (t_text *)malloc(sizeof(*text));
	if (text == NULL)
		exit(exit_error(data, "Memory allocation failed"));
	text->mlx_img = NULL;
	text->width = 0;
	text->height = 0;
	return (text);
}

t_scene	*scene_init(t_data *data)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(*scene));
	if (scene == NULL)
		exit(exit_error(data, "Memory allocation failed"));
	scene->win_width = 0;
	scene->win_height = 0;
	scene->map_w = 0;
	scene->map_h = 0;
	scene->sprite = 0;
	scene->exit = 0;
	scene->player = 0;
	scene->tmp = NULL;
	return (scene);
}

t_player	*player_init(t_data *data)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(*player));
	if (player == NULL)
		exit(exit_error(data, "Memory allocation failed"));
	player->speed = 1;
	player->moves = 0;
	player->dir_x = 1;
	player->dir_y = 1;
	return (player);
}

t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(*data));
	if (data == NULL)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		exit(1);
	}
	data->img = img_init(data);
	if (data->img == NULL)
	{
		free(data);
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		exit(1);
	}
	init_to_null(data);
	data->text_wall = text_init(data);
	data->text_sprite = text_init(data);
	data->text_exit = text_init(data);
	data->text_player = text_init(data);
	data->text_empty = text_init(data);
	data->player = player_init(data);
	data->scene = scene_init(data);
	return (data);
}
