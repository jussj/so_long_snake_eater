/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:02:40 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/18 13:48:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_map_closed(t_data *data, char **tab)
{
	int	i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((i == 0 || i == (data->scene->map_height - 1)) && tab[i][j] != WALL)
				return (1);
			if ((j == 0 || j == (data->scene->map_width - 1)) && tab[i][j] != WALL)
				return (1);
			if (tab[i][j] != WALL && tab[i][j] != EMPTY && tab[i][j] != SPRITE
				&& tab[i][j] != EXIT && tab[i][j] != PLAYER)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int init_map(t_data *data)
{
	int map_height;
	int map_width;

	map_height = 0;
	while (data->scene->map[map_height])
		map_height++;
	map_width = ft_strlen(data->scene->map[0]);
	if (map_height > 0 || map_width > 0 || map_height != map_width)
	{
		data->scene->win_width = map_width * CELL_WIDTH;
		data->scene->win_height = (map_height * CELL_WIDTH) + 100;
		data->scene->map_width = map_width;
		data->scene->map_height = map_height;
		return (0);
	}
	exit(exit_error(data, "Invalid map format", 1));
}

int inspect_map(t_data *data)
{
	int i;
	int j;
	int ret;

	i = 0;
	ret = 0;
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
				data->player->x = j;
				data->player->y = i;
			}
			else if (data->scene->map[i][j] != WALL
				&& data->scene->map[i][j] != EMPTY)
				exit(exit_error(data, "Invalid map components", PARSING_ERROR));
			j++;
		}
		i++;
	}
// LEAKS ON ERROR EXIT
	if (data->scene->sprite < 1 || data->scene->exit < 1 || data->scene->player != 1)
		exit(exit_error(data, "Invalid map components", PARSING_ERROR));
	ret = is_map_closed(data, data->scene->map);
	if (ret == 1)
		exit(exit_error(data, "Map isn't closed", PARSING_ERROR));
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

int parsing_scene(t_data *data, int ac, char **av)
{
	int i;
	int fd;
	char *line;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(exit_error(data, "Invalid map file", FILE_ERROR));
	while ((i = get_next_line(fd, &line)) > 0)
		get_map(line, data);
	get_map(line, data);
	data->scene->map = ft_split(data->scene->tmp, '|');
	free(data->scene->tmp);
	init_map(data);
	inspect_map(data);
	return (0);
}