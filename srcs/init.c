/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:35:56 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/01 17:39:00 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img *img_init(void)
{
	t_img *img;

	img = malloc(sizeof(*img));
	return (img);
}

t_scene *scene_init(void)
{
	t_scene *scene;

	scene = malloc(sizeof(*scene));
	scene->win_width = 800;
	scene->win_height = 500;
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

	player = malloc(sizeof(*player));
	player->speed = 1;
	player->dir_x = 1;
	player->dir_y = 1;

// WHAT IS THE PLAN WHERE IS THE PLANE
//	player->plan_x = 0.66;
//	player->plan_y = 0;
	return (player);
}


t_data *data_init(void)
{
	t_data *data;

	data = malloc(sizeof(*data));
	data->scene = scene_init();
	data->img = img_init();
	data->player = player_init();

	return(data);
}