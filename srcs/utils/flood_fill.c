
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