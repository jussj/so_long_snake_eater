/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:36:11 by jusaint-          #+#    #+#             */
/*   Updated: 2021/10/28 16:34:39 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
}

int cmd_left(t_data *data)
{
	float new_pos_x;
	float new_pos_y;

	new_pos_x = data->player->x - data->player->plan_x * data->player->speed;
	new_pos_y = data->player->y - data->player->plan_y * data->player->speed;
	if (data->scene->map[(int)(new_pos_y + 0.50)][(int)(new_pos_x + 0.50)] != WALL)
	{
		data->player->x = new_pos_x;
		data->player->y = new_pos_y;
		return (0);
	}
	else
		return (1);
}

int	cmd_right(t_data *data)
{
	float new_pos_x;
	float new_pos_y;

	new_pos_x = data->player->x + data->player->plan_x * data->player->speed;
	new_pos_y = data->player->y + data->player->plan_y * data->player->speed;
	if (data->scene->map[(int)(new_pos_y + 0.50)][(int)(new_pos_x + 0.50)] != WALL)
	{
		data->player->x = new_pos_x;
		data->player->y = new_pos_y;
		return (0);
	}
	else
		return (1);
}

int cmd_up(t_data *data)
{
	float new_pos_x;
	float new_pos_y;

	new_pos_x = data->player->x + data->player->dir_x * data->player->speed;
	new_pos_y = data->player->y + data->player->dir_y * data->player->speed;
	if (data->scene->map[(int)(new_pos_y + 0.50)][(int)(new_pos_x + 0.50)] != WALL)
	{
		data->player->x = new_pos_x;
		data->player->y = new_pos_y;
		return (0);
	}
	else
		return (1);
}

int cmd_down(t_data *data)
{
	float new_pos_x;
	float new_pos_y;

	new_pos_x = data->player->x - data->player->dir_x * data->player->speed;
	new_pos_y = data->player->y - data->player->dir_y * data->player->speed;
	if (data->scene->map[(int)(new_pos_y + 0.50)][(int)(new_pos_x + 0.50)] != WALL)
	{
		data->player->x = new_pos_x;
		data->player->y = new_pos_y;
		return (0);
	}
	else
		return (1);
}

int handle_keypress(int keysym, t_data *data)
{ 
	if (keysym == XK_space)
		player_coordinates(data);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (EXIT_SUCCESS);
	}
	if (keysym == XK_Left)
		cmd_left(data);
	if (keysym == XK_Right)
		cmd_right(data);
	if (keysym == XK_Up)
		cmd_up(data);
	if (keysym == XK_Down)
		cmd_down(data);
	return (0);
}


