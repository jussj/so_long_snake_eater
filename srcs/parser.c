/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:02:40 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/04 13:33:04 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int flood_fill(int flood_x, int flood_y, int empty, int wall)
{
	if (map[flood_x][flood_y] == wall || map[flood_x][flood_y] == 2
		|| map[flood_x][flood_y] == 'P')
		return;
	if (map[flood_x][flood_y] == empty || map[flood_x][flood_y] == 'C'
		|| map[flood_x][flood_y] == 'E')
}

int is_map_closed(t_data *data)
{
	char **map;
	int flood_x;
	int flood_y;

	map = data->scene->map;
	flood_x = data->player->x;
	flood_y = data->player->y;
}*/

int init_map(t_data *data)
{
	int map_height;
	int map_width;

	map_height = 0;
	while (data->scene->map[map_height])
		map_height++;
	map_width = ft_strlen(data->scene->map[0]);
	if (map_height < map_width)
	{
		data->scene->win_width = map_width * CELL_WIDTH;
		data->scene->win_height = (map_height * CELL_WIDTH) + 100;
		return (0);
	}
	exit(error_exit(data, "ERROR: INVALID MAP", 1));

}

int inspect_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->scene->map[i])
	{
		j = 0;
		while (data->scene->map[i][j])
		{
			if (data->scene->map[i][j] == SPRITE)
				data->scene->sprite++;
			else if (data->scene->map[i][j] == EXIT)
				data->scene->exit++;
			else if (data->scene->map[i][j] == PLAYER)
			{
				data->scene->player++;
				player_coordinates(data);
			}
			j++;
		}
		i++;
	}
	if (data->scene->sprite < 1 || data->scene->exit < 1 || data->scene->player != 1)
		exit(error_exit(data, "ERROR: INVALID MAP", 1));
//	is_map_closed(data);
	return (0);
}

int get_map(char *line, t_data *data)
{
	int i;

	i = 0;
	while (ft_iswhitespace(line[i]) == 1)
		i++;
	if (ft_isdigit(line[i]) == 1)
	{
		if (!data->scene->tmp)
			data->scene->tmp = memdup(line, ft_strlen(line) - 1);
		else
		{
			data->scene->tmp = memjoin(data->scene->tmp, "|", 0);
			data->scene->tmp = memjoin(data->scene->tmp, line, ft_strlen(line) - 1);
		}
		free(line);
		return (0);
	}
	else
	{
		free(line);
		return (1);
	}
}

// check whether map is closed and is rectangular


int parsing_scene(t_data *data, int ac, char **av)
{
	int i;
	int fd;
	int ret;
	char *line;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
		get_map(line, data);
	get_map(line, data);
	data->scene->map = ft_split(data->scene->tmp, '|');
	free(data->scene->tmp);
	init_map(data);
	inspect_map(data);
	printf("MAP:\n");
	i = 0;
	while (data->scene->map[i])
	{
		printf("%s\n", data->scene->map[i]);
		i++;
	}
	return (0);
}