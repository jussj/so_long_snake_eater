/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:10:21 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/25 12:02:25 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_coordinates(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	if (x > 0 && y > 0)
	{
		data->player->x = x;
		data->player->y = y;
		return ;
	}
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

void	init_to_null(t_data *data)
{
	data->win_ptr = NULL;
	data->mlx_ptr = NULL;
	data->img->mlx_img = NULL;
	data->scene = NULL;
	data->player = NULL;
	data->text_player = NULL;
	data->text_empty = NULL;
	data->text_wall = NULL;
	data->text_sprite = NULL;
	data->text_exit = NULL;
}
