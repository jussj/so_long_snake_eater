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

# define CELL_WIDTH 40
# define WHITE 0x00FFFFFF
# define BLUE 0x000000FF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLACK 0x0
# define PI 3.14159265359

# define WALL '1'
# define SPRITE 'C'
# define EMPTY '0'
# define PLAYER 'P'
# define EXIT 'E'

// SCENE RENDERING

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

// SCENE DATA

typedef struct	s_scene
{
	int		win_width;
	int		win_height;
	char 	**map;
	char 	*tmp;
	int		sprite;
	int		exit;
	int		player;
}				t_scene;

typedef struct 	s_player
{
	int color;
	int moves;
	float speed;
//	float plan_x;
//	float plan_y;
	float dir_x;
	float dir_y;
	float x;
	float y;
}				t_player;

// CONTROL STRUCTURE

typedef struct	s_data
{
	t_scene		*scene;
	t_img		*img;
	t_player	*player;
	void		*mlx_ptr;
	void		*win_ptr;
	
}				t_data;

// INIT

void		player_coordinates(t_data *data);
t_data		*data_init(void);
t_player	*player_init(void);
t_scene		*scene_init(void);
t_img		*img_init(void);

// PARSER

int			parsing_scene(t_data *data, int ac, char **av);
int			get_map(char *line, t_data *data);
int			inspect_map(t_data *data);

// RENDER

void		 img_pix_put(t_img *img, int x, int y, int color);
int 		render_background(t_data *data, int color);
int 		render_cell(t_data *data, double x, double y, int color);
int 		render_map(t_data *data);
int			render_player(t_data *data);
int			render_angle(t_data *data, int color, float width);
int 		render(t_data *data);
int 		render_init(t_data *data);

// COMMANDS

int			handle_keypress(int keysym, t_data *data);
int			cmd_left(t_data *data);
int			cmd_right(t_data *data);
int			cmd_up(t_data *data);
int			cmd_down(t_data *data);
int			close_window(t_data *data);

void		trigger_collect(t_data *data, int pos_x, int pos_y);
void		trigger_exit(t_data *data, int pos_x, int pos_y);

// UTILS

int			debug_info(t_data *data);
int			error_exit(t_data *data, char *msg, int ret_value);
char		*memjoin(char *s1, char *s2);

#endif