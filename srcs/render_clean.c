/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:49:23 by anonymous         #+#    #+#             */
/*   Updated: 2021/11/18 13:48:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_texture_ptr(t_data *data)
{
	free(data->text_player);
	free(data->text_empty);
	free(data->text_wall);
	free(data->text_sprite);
	free(data->text_exit);
}

void	free_data(t_data *data)
{
	free_tab(data->scene->map);
	free(data->scene);
	free_texture_ptr(data);
	free(data->img);
//	free(data->mlx_ptr);
	free(data->player);
	free(data);
}

void	destroy_render(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_player->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_wall->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_empty->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_exit->mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->text_sprite->mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int exit_success(t_data *data)
{
	destroy_render(data);
	free_data(data);
	return (0);
}

int	exit_error(t_data *data, char *msg, int ret_value)
{
	if (msg)
	{
		write(2, "Error\n", 6);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	if (ret_value == PARSING_ERROR)
		free_data(data);
	else if (ret_value == FILE_ERROR)
	{
		free_texture_ptr(data);
		free(data->scene);
		free(data->player);
		free(data->img);
		free(data);
	}
	else
	{
		destroy_render(data);
		free_data(data);
	}
	return (1);
}