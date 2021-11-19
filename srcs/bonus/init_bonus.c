/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:49:13 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/19 11:49:21 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img *img_init(void)
{
	t_img *img;

	img = (t_img *)malloc(sizeof(*img));
	return (img);
}

t_text *text_init(void)
{
	t_text	*text;

	text = (t_text *)malloc(sizeof(*text));
	text->width = 0;
	text->height = 0;
	return (text);
}

t_scene *scene_init(void)
{
	t_scene *scene;

	scene = (t_scene *)malloc(sizeof(*scene));
	scene->win_width = 800;
	scene->win_height = 500;
	scene->map_width = 0;
	scene->map_height = 0;
	scene->sprite = 0;
	scene->exit = 0;
	scene->player = 0;
	scene->tmp = NULL;

	return (scene);
}

void	player_coordinates(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->scene->map[i])
	{
		j = 0;
		while (data->scene->map[i][j])
		{
			if (data->scene->map[i][j] == 'P')
			{
				data->player->x = j;
				data->player->y = i;
			}
			j++;
		}
		i++;
	}
}

t_player *player_init(void)
{
	t_player *player;

	player = (t_player *)malloc(sizeof(*player));
	player->speed = 1;
	player->moves = 0;
	player->dir_x = 1;
	player->dir_y = 1;
	return (player);
}


t_data *data_init(void)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(*data));
	data->scene = scene_init();
	data->img = img_init();
	data->text_wall = text_init();
	data->text_sprite = text_init();
	data->text_exit = text_init();	
	data->text_player = text_init();
	data->text_empty = text_init();
	data->player = player_init();

	return(data);
}