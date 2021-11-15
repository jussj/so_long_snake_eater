/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:36:11 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/15 15:07:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(exit_success(data));
}

int cmd_left(t_data *data)
{
	float new_pos_x;

	new_pos_x = data->player->x - data->player->dir_x * data->player->speed;
	if (data->scene->map[(int)(data->player->y + 0.50)][(int)(new_pos_x + 0.50)] != WALL)
	{
		data->player->x = new_pos_x;
		data->player->moves++;
		return (0);
	}
	else
		return (1);
}

int	cmd_right(t_data *data)
{
	float new_pos_x;

	new_pos_x = data->player->x + data->player->dir_x * data->player->speed;
	if (data->scene->map[(int)(data->player->y + 0.50)][(int)(new_pos_x + 0.50)] != WALL)
	{
		data->player->x = new_pos_x;
		data->player->moves++;
		return (0);
	}
	else
		return (1);
}

int cmd_up(t_data *data)
{
	float new_pos_y;

	new_pos_y = data->player->y - data->player->dir_y * data->player->speed;
	if (data->scene->map[(int)(new_pos_y + 0.50)][(int)(data->player->x + 0.50)] != WALL)
	{
		data->player->y = new_pos_y;
		data->player->moves++;
		return (0);
	}
	else
		return (1);
}

int cmd_down(t_data *data)
{
	float new_pos_y;

	new_pos_y = data->player->y + data->player->dir_y * data->player->speed;
	if (data->scene->map[(int)(new_pos_y + 0.50)][(int)(data->player->x + 0.50)] != WALL)
	{
		data->player->y = new_pos_y;
		data->player->moves++;
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
		exit(exit_success(data));
	}
	if (keysym == XK_Left || keysym == XK_a  || keysym == XK_A)
		cmd_left(data);
	if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
		cmd_right(data);
	if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
		cmd_up(data);
	if (keysym == XK_Down || keysym == XK_s  || keysym == XK_S)
		cmd_down(data);
	trigger_collect(data, data->player->x, data->player->y);
	trigger_exit(data, data->player->x, data->player->y);
	return (0);
}


