/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:02:40 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/06 16:46:20 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int flood_fill(t_data *data, char **map, int flood_x, int flood_y)
{
	if (flood_x < 0 || flood_x >= data->scene->map_height 
		|| flood_y < 0 || flood_y >= data->scene->map_width)
        return (1);
	if (map[flood_x][flood_y] == WALL || map[flood_x][flood_y] == '-')
		return (1);
	if (map[flood_x][flood_y] == EMPTY || map[flood_x][flood_y] == 'C'
		|| map[flood_x][flood_y] == 'E' || map[flood_x][flood_y] == 'P')
		map[flood_x][flood_y] = '-';
//	int i = 0;
//	while (data->scene->map[i])
//	{
//		printf("%s\n", map[i]);
//		i++;
//	}	
//	printf("FLOOD X %d Y %d\n", flood_x, flood_y);
	flood_fill(data, map, flood_x + 1, flood_y);
	flood_fill(data, map, flood_x - 1, flood_y);
	flood_fill(data, map, flood_x, flood_y + 1);
	flood_fill(data, map, flood_x, flood_y - 1);
	return (0);
}

char **tabdup(char **tab)
{
	char	**ret;
	int len;
	int		i;
	int		j;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	ret = (char **)malloc(sizeof(*tab) * (len + 1));
	if (!ret)
		return (NULL);
	while (tab[i])
	{
		j = 0;
		ret[i] = (char *)malloc(sizeof(char) * ft_strlen(tab[i]) + 1);
		if (!ret[i])
			return (NULL);
		while (tab[i][j])
		{
			ret[i][j] = tab[i][j];
			j++;
		}
		ret[i][j] = '\0';
		i++;
	}
	return (ret);
}

int is_map_closed(t_data *data)
{
	char **map;
	int ret;
	int flood_x;
	int flood_y;

	map = tabdup(data->scene->map);
	flood_x = data->player->x;
	flood_y = data->player->y;
	ret = flood_fill(data, map, flood_x, flood_y);
	printf("RET FLOOD FILL %d\n", ret);
  	free_tab(map);
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
				data->player->x = j;
				data->player->y = i;
			}
			j++;
		}
		i++;
	}
	if (data->scene->sprite < 1 || data->scene->exit < 1 || data->scene->player != 1)
		exit(error_exit(data, "ERROR: INVALID MAP", 1));
	is_map_closed(data);
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