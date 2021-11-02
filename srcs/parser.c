/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:02:40 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/02 22:21:10 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int flood_fill(t_data *data)
*/

int is_map_valid(t_data *data)
{
	int map_height;
	int map_width;

	map_height = 0;
	while (data->scene->map[map_height])
		map_height++;
	// remove last char from map lines
	map_width = ft_strlen(data->scene->map[0]) - 1;
	if (map_height < map_width)
	{
		data->scene->win_width = (map_width * CELL_WIDTH);
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
	is_map_valid(data);
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
				data->scene->player++;
			j++;
		}
		i++;
	}
	if (data->scene->sprite < 1 || data->scene->exit < 1 || data->scene->player != 1)
		return (1);
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
			data->scene->tmp = ft_strdup(line);
		else
		{
			data->scene->tmp = memjoin(data->scene->tmp, "|");
			data->scene->tmp = memjoin(data->scene->tmp, line);
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

// P player's starting position (at least one)
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
	ret = inspect_map(data);
	if (ret == 1)
		exit(1);
	printf("MAP:\n");
	i = 0;
	while (data->scene->map[i])
	{
		printf("%s\n", data->scene->map[i]);
		i++;
	}
	return (0);
}