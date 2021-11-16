/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:23:45 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/16 14:44:28 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int take_pix(int x, int y, t_text *text)
{
	unsigned int 	color;
	unsigned int	*addr_int;

	addr_int = (unsigned int *)text->addr;
	color = *(addr_int + y * (text->line_len / 4) + x);

	return (color);
}

int render_text(t_data *data, int x, int y, t_text *text)
{
	int i;
	int j;
	int	color;
	
	i = 0;
	while (i < CELL_WIDTH)
	{
		j = 0;
		while (j < CELL_WIDTH)
		{
			color = take_pix(j * text->width / CELL_WIDTH, i * text->height / CELL_WIDTH, text);
			img_pix_put(data->img, x * CELL_WIDTH + j, y * CELL_WIDTH + i, color);
			j++;
		}
		i++;
	}
	return (0);
}

int texture_init(t_data *data, t_text *texture, char *path)
{
//	FREE AND DESTROY IN CASE OF ERROR
	texture->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, 
		&texture->width, &texture->height);
	if (texture->mlx_img == NULL)
		return (1);
	texture->addr = mlx_get_data_addr(texture->mlx_img, &texture->bpp, 
		&texture->line_len, &texture->endian);
	if (texture->addr == NULL)
		return (1);
	return (0);
}

int load_all_textures(t_data *data)
{
	texture_init(data, data->text_player, "srcs/textures/snake.xpm");
	texture_init(data, data->text_empty, "srcs/textures/empty-2.xpm");
	texture_init(data, data->text_wall, "srcs/textures/wall-1.xpm");
	texture_init(data, data->text_sprite, "srcs/textures/collectible-1.xpm");
	texture_init(data, data->text_exit, "srcs/textures/exit-1.xpm");
	return (0);
}