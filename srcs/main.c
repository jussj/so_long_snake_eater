/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:36:41 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/15 15:11:33 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		exit(exit_error(NULL, "Error\nNo map given", 0));
	data = data_init();
	parsing_scene(data, ac, av);
	render_init(data);
	free_init_data(data);
	return (0);
}