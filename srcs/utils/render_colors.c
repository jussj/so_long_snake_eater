
int render_cell(t_data *data, double x, double y, int color)
{
	int i;
	int j;
	
	x *= CELL_WIDTH;
	y *= CELL_WIDTH;
	i = y;
	while (i < y + CELL_WIDTH)
	{
		j = x;
		while (j < x + CELL_WIDTH)
		{
//			if (j == x || i == y)
//				img_pix_put(data->img, j, i, BLUE);
//			else
				img_pix_put(data->img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}

int	render_player(t_data *data)
{
	int i;
	int j;
	int x;
	int y;

	x = data->player->x * CELL_WIDTH;
	y = data->player->y * CELL_WIDTH;
	i = y;
	while (i < y + CELL_WIDTH)
	{
		j = x;
		while (j < x + CELL_WIDTH)
		{
			img_pix_put(data->img, j, i, 0x878787);
			j++;
		}
		i++;
	}
	return (0);
}