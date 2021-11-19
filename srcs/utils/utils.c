/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:10:21 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/19 18:18:07 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	debug_info(t_data *data)
{
	char buff[150];
	int dis;

	dis = data->scene->win_height - 100;
	sprintf(buff, "COLLECTIBLES LEFT %2d", data->scene->sprite);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, dis + 20, 0xFFFFFF, buff);
	sprintf(buff, "NUMBER OF MOVES   %2d", data->player->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, dis + 35, 0xFFFFFF, buff);
	sprintf(buff, "COORDINATES X %2f Y %2f", data->player->x, data->player->y);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, dis + 50, 0xFFFFFF, buff);
	return (0);	
}

int	check_extension(char *filename, char *suffix)
{
	int i;
	int index;

	i = 0;
	index = ft_strlen(filename) - ft_strlen(suffix);
	while (filename[i])
	{
		if (filename[i] == '.' && i == index - 1)
		{
			i++;
			if (ft_strncmp(&filename[i], suffix, ft_strlen(suffix)) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

char	*memjoin(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (n < 1)
		n = ft_strlen(s2);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] && i < n)
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*memdup(char *s, int n)
{
	char	*dup;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (n < 1)
		n = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * n + 1);
	if (!dup)
		return (NULL);
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
