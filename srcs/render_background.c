/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:21:53 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/16 14:27:10 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int render_background(t_data *data, int color)
{
	int i;
	int j;

	i = 0;
	while (i < data->scene->win_height)
	{
		j = 0;
		while (j < data->scene->win_width)
			img_pix_put(data->img, j++, i, color);
		i++;
	}
	return (0);	
}