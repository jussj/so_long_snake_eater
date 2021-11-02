/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:18:41 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/02 16:42:57 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		debug_info(t_data *data)
{
	char buff[150];

//	sprintf(buff, "DIRECTIONS  X %2f Y %2f", data->player->dir_x, data->player->dir_y);
	sprintf(buff, "COLLECTIBLES LEFT %2d", data->scene->sprite);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 265, 0xFFFFFF, buff);
	sprintf(buff, "NUMBER OF MOVES   %2d", data->player->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 280, 0xFFFFFF, buff);
	sprintf(buff, "COORDINATES X %2f Y %2f", data->player->x, data->player->y);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 295, 0xFFFFFF, buff);
	return (0);	
}

int	error_exit(t_data *data, char *msg, int ret_value)
{
	(void)data;
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	return (ret_value);
}