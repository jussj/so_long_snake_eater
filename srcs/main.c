/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:36:41 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/06 16:48:37 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_data(t_data *data)
{
	free_tab(data->scene->map);
	free(data->scene);
	free(data->img);
	free(data->player);
	free(data);
	
	return (0);
}

int main(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		exit(error_exit(NULL, "ERROR: NO MAP", 1));
	data = data_init();
	parsing_scene(data, ac, av);
	render_init(data);
	free_data(data);
	return (0);
}