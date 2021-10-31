/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_collect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:44:40 by jusaint-          #+#    #+#             */
/*   Updated: 2021/10/31 17:42:12 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void cmd_collect(t_data *data, int pos_x, int pos_y)
{

	if (data->scene->map[(int)(pos_y + 0.50)][(int)(pos_x + 0.50)] == SPRITE)
	{
		data->scene->map[(int)(pos_y + 0.50)][(int)(pos_x + 0.50)] = EMPTY;
		data->scene->sprite--;
	}
}

void cmd_exit(t_data *data, int pos_x, int pos_y)
{
	if (data->scene->map[(int)(pos_y + 0.50)][(int)(pos_x + 0.50)] == EXIT
		&& data->scene->sprite == 0)
	{
		printf("GG\n");
		close_window(data);
	}
	else
		return ;
}
