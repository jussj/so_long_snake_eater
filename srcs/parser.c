/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:02:40 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/25 14:52:18 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_closed(t_data *data, char **tab)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(data->scene->map[i]);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((i == 0 || i == (data->scene->map_h) - 1) && tab[i][j] != WALL)
				return (1);
			if ((j == 0 || j == (data->scene->map_w) - 1) && tab[i][j] != WALL)
				return (1);
			if (tab[i][j] != WALL && tab[i][j] != EMPTY && tab[i][j] != SPRITE
				&& tab[i][j] != EXIT && tab[i][j] != PLAYER)
				return (1);
			j++;
		}
		if ((int)ft_strlen(data->scene->map[i]) != len)
			exit(exit_error(data, "Invalid map format"));
		i++;
	}
	return (0);
}

int	init_map(t_data *data)
{
	int	map_height;
	int	map_width;

	map_height = 0;
	if (!data->scene->map)
		exit(exit_error(data, "Empty map"));
	while (data->scene->map[map_height])
		map_height++;
	map_width = ft_strlen(data->scene->map[0]);
	if (map_height > 0 || map_width > 0 || map_height != map_width)
	{
		data->scene->win_width = map_width * CELL_WIDTH;
		data->scene->win_height = (map_height * CELL_WIDTH);
		data->scene->map_w = map_width;
		data->scene->map_h = map_height;
		return (0);
	}
	exit(exit_error(data, "Invalid map format"));
}

void	inspect_map(t_data *data)
{
	int	i;
	int	j;

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
				player_coordinates(data, j, i);
			}
			else if (data->scene->map[i][j] != WALL
				&& data->scene->map[i][j] != EMPTY)
				exit(exit_error(data, "Invalid map components"));
			j++;
		}
		i++;
	}
}

int	get_map(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (ft_isdigit(line[i]) == 1)
	{
		if (!data->scene->tmp)
			data->scene->tmp = memdup(line, ft_strlen(line));
		else
		{
			data->scene->tmp = memjoin(data->scene->tmp, "|", 0);
			data->scene->tmp = memjoin(data->scene->tmp, line, ft_strlen(line));
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

void	parsing_scene(t_data *data, char **av)
{
	int		i;
	int		fd;
	char	*line;

	if (check_extension(av[1], "ber") == 0)
		exit(exit_error(data, "Invalid file extension"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(exit_error(data, "Invalid map file"));
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		get_map(line, data);
		i = get_next_line(fd, &line);
	}
	get_map(line, data);
	data->scene->map = ft_split(data->scene->tmp, '|');
	free(data->scene->tmp);
	init_map(data);
	inspect_map(data);
	if (data->scene->sprite < 1 || data->scene->exit < 1
		|| data->scene->player != 1)
		exit(exit_error(data, "Invalid map components"));
	if (is_map_closed(data, data->scene->map) == 1)
		exit(exit_error(data, "Map isn't closed"));
}
