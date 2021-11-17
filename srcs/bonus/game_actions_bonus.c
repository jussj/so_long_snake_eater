/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:38:39 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/17 18:11:47 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
//	clean_render(data);
	exit(exit_success(data));
}

void trigger_collect(t_data *data, int pos_x, int pos_y)
{

	if (data->scene->map[(int)(pos_y + 0.50)][(int)(pos_x + 0.50)] == SPRITE)
	{
		data->scene->map[(int)(pos_y + 0.50)][(int)(pos_x + 0.50)] = EMPTY;
		data->scene->sprite--;
	}
}

void trigger_exit(t_data *data, int pos_x, int pos_y)
{
	if (data->scene->map[(int)(pos_y + 0.50)][(int)(pos_x + 0.50)] == EXIT
		&& data->scene->sprite == 0)
		close_window(data);
	if (data->scene->map[(int)(pos_y + 0.50)][(int)(pos_x + 0.50)] == 'X')
		close_window(data);
	else
		return ;
}

int	handle_keypress(int keysym, t_data *data)
{ 
	if (keysym == XK_space)
		player_coordinates(data);
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == XK_Left || keysym == XK_a  || keysym == XK_A)
		cmd_left(data);
	if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
		cmd_right(data);
	if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
		cmd_up(data);
	if (keysym == XK_Down || keysym == XK_s  || keysym == XK_S)
		cmd_down(data);
// 	CHANGE FUNCC NAME FOR EVENTS
	trigger_collect(data, data->player->x, data->player->y);
	trigger_exit(data, data->player->x, data->player->y);
	return (0);
}