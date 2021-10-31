/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:02:40 by jusaint-          #+#    #+#             */
/*   Updated: 2021/10/31 17:18:33 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			j++;
		}
		i++;
	}
	if (data->scene->sprite == 0 || data->scene->exit == 0)
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
			data->scene->tmp = ft_strjoin(data->scene->tmp, "|");
			data->scene->tmp = ft_strjoin(data->scene->tmp, line);
		}
		free(line);
		return (0);
	}
	else
	{
		// free tab
		return (1);
	}
}

// identify C collectibles (at least one)
// E map exit (at least one)
// P player's starting position (at least one)
// check whether map is closed and is rectangular


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
	inspect_map(data);
	printf("MAP:\n");
	i = 0;
	while (data->scene->map[i])
	{
		printf("%s\n", data->scene->map[i]);
		i++;
	}
	printf("SPRITE: %d\n", data->scene->sprite);
	printf("EXIT: %d\n", data->scene->exit);
	return (0);
}