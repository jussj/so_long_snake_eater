/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:49:23 by anonymous         #+#    #+#             */
/*   Updated: 2021/11/15 22:31:48 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data_structure(t_text *texture)
{
	printf("ENTERING FREE STRUCTURE\n");
	free(texture->mlx_img);
//	free(texture->addr);
	free(texture);
}

void	free_texture_data(t_data *data)
{
	printf("ENTERING FREE TEXTURE\n");
	free_data_structure(data->text_player);
	free_data_structure(data->text_empty);
	free_data_structure(data->text_wall);
	free_data_structure(data->text_sprite);
	free_data_structure(data->text_exit);
}

void	free_init_data(t_data *data)
{
	printf("ENTERING FREE INIT\n");
// free all parsed data
	free_tab(data->scene->map);
	free(data->scene);
// free all textures
	free_texture_data(data);
// free img data
	free(data->img->mlx_img);
//	free(data->img->mlx_img->data);
//	free(data->img->addr);
	free(data->img);
	free(data->player);
// free ptr data
	free(data->mlx_ptr);
//	free(data->win_ptr);
	free(data);
}

void	clean_render(t_data *data)
{
	printf("ENTERING CLEAN RENDER\n");
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
// clean off all textures	
	mlx_destroy_image(data->mlx_ptr, data->text_player->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_wall->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_empty->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_exit->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_sprite->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
}