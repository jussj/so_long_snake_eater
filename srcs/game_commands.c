/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:20:09 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/23 15:06:01 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cmd_left(t_data *data)
{
	float	new_pos_x;

	new_pos_x = data->player->x - data->player->dir_x * data->player->speed;
	if (data->scene->map[(int)(data->player->y + 0.50)]
		[(int)(new_pos_x + 0.50)] != WALL)
	{
		data->player->x = new_pos_x;
		data->player->moves++;
		print_moves(data->player->moves);
		return (0);
	}
	else
		return (1);
}

int	cmd_right(t_data *data)
{
	float	new_pos_x;

	new_pos_x = data->player->x + data->player->dir_x * data->player->speed;
	if (data->scene->map[(int)(data->player->y + 0.50)]
		[(int)(new_pos_x + 0.50)] != WALL)
	{
		data->player->x = new_pos_x;
		data->player->moves++;
		print_moves(data->player->moves);
		return (0);
	}
	else
		return (1);
}

int	cmd_up(t_data *data)
{
	float	new_pos_y;

	new_pos_y = data->player->y - data->player->dir_y * data->player->speed;
	if (data->scene->map[(int)(new_pos_y + 0.50)]
		[(int)(data->player->x + 0.50)] != WALL)
	{
		data->player->y = new_pos_y;
		data->player->moves++;
		print_moves(data->player->moves);
		return (0);
	}
	else
		return (1);
}

int	cmd_down(t_data *data)
{
	float	new_pos_y;

	new_pos_y = data->player->y + data->player->dir_y * data->player->speed;
	if (data->scene->map[(int)(new_pos_y + 0.50)]
		[(int)(data->player->x + 0.50)] != WALL)
	{
		data->player->y = new_pos_y;
		data->player->moves++;
		print_moves(data->player->moves);
		return (0);
	}
	else
		return (1);
}


