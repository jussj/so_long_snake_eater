/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:21:36 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/23 19:24:00 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
	{
		write(2, "Error\nNo map given", 18);
		return (1);
	}
	data = data_init();
	parsing_scene(data, ac, av);
	render_init(data);
	free_data(data);
	return (0);
}
