/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:36:41 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/04 13:06:26 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_data(t_data *data)
{
	int i;

	i = 0;
	while(data->scene->map[i])
	{
		free(data->scene->map[i]);
		i++;
	}
	free(data->scene->map);
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
//	player_coordinates(data);
	render_init(data);
	free_data(data);
	return (0);
}