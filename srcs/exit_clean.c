/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:35:51 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/25 12:32:10 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_texture_ptr(t_data *data)
{
	if (data->text_player != NULL)
		free(data->text_player);
	if (data->text_empty != NULL)
		free(data->text_empty);
	if (data->text_wall != NULL)
		free(data->text_wall);
	if (data->text_sprite != NULL)
		free(data->text_sprite);
	if (data->text_exit != NULL)
		free(data->text_exit);
}

void	free_data(t_data *data)
{
	free_texture_ptr(data);
	if (data->scene != NULL)
	{
		free_tab(data->scene->map);
		free(data->scene);
	}
	if (data->img != NULL)
		free(data->img);
	if (data->player != NULL)
		free(data->player);
	free(data);
}

void	destroy_render(t_data *data)
{
	if (data->img->mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	if (data->text_player->mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->text_player->mlx_img);
	if (data->text_wall->mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->text_wall->mlx_img);
	if (data->text_empty->mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->text_empty->mlx_img);
	if (data->text_exit->mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->text_exit->mlx_img);
	if (data->text_sprite->mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->text_sprite->mlx_img);
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
