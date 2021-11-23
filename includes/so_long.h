/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:14:05 by jusaint-          #+#    #+#             */
/*   Updated: 2021/11/23 18:52:53 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>

# include "../libft/libft.h"

# define CELL_WIDTH 80
# define BLACK 0

# define WALL '1'
# define SPRITE 'C'
# define EMPTY '0'
# define PLAYER 'P'
# define EXIT 'E'

// SCENE RENDERING

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_text
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_text;

// SCENE DATA

typedef struct s_scene
{
	int		win_width;
	int		win_height;
	int		map_width;
	int		map_height;
	char	**map;
	char	*tmp;
	int		sprite;
	int		exit;
	int		player;
}				t_scene;

typedef struct s_player
{
	int		color;
	int		moves;
	float	speed;
	float	dir_x;
	float	dir_y;
	float	x;
	float	y;
}				t_player;

// CONTROL STRUCTURE

typedef struct s_data
{
	t_scene		*scene;
	t_img		*img;
	t_text		*text_player;
	t_text		*text_empty;
	t_text		*text_wall;
	t_text		*text_sprite;
	t_text		*text_exit;	
	t_player	*player;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

// INIT

void		player_coordinates(t_data *data);
t_data		*data_init(void);

// PARSER

void		parsing_scene(t_data *data, int ac, char **av);
int			check_extension(char *filename, char *suffix);

// RENDER

void		img_pix_put(t_img *img, int x, int y, int color);
int			render_background(t_data *data, int color);
int			render_init(t_data *data);
int			render_text(t_data *data, int x, int y, t_text *text);
void		render_clean(t_data *data);
int			load_all_textures(t_data *data);
int			print_moves(int moves);

// COMMANDS

int			handle_keypress(int keysym, t_data *data);
int			cmd_left(t_data *data);
int			cmd_right(t_data *data);
int			cmd_up(t_data *data);
int			cmd_down(t_data *data);
int			close_window(t_data *data);

void		trigger_collect(t_data *data, int pos_x, int pos_y);
void		trigger_exit(t_data *data, int pos_x, int pos_y);

// WHEN I'M CLEANING WINDOWS

void		free_tab(char **tab);
void		free_texture_ptr(t_data *data);
void		free_data(t_data *data);
void		destroy_render(t_data *data);
int			exit_error(t_data *data, char *msg);
int			exit_success(t_data *data);

// UTILS

int			debug_info(t_data *data);
char		*memjoin(char *s1, char *s2, int n);
char		*memdup(char *s, int n);

#endif