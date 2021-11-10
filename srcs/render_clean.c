/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:59:16 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/07 11:37:40 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_render(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_player->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}