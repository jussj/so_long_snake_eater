/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:18:41 by jusaint-          #+#    #+#             */
/*   Updated: 2021/10/29 18:44:42 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		debug_info(t_data *data)
{
	char buff[150];

	sprintf(buff, "DIRECTIONS  X %2f Y %2f", data->player->dir_x, data->player->dir_y);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 245, 0xFFFFFF, buff);
	sprintf(buff, "COORDINATES X %2f Y %2f", data->player->x, data->player->y);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 260, 0xFFFFFF, buff);
	return (0);	
}