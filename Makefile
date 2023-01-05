NAME		=	so_long_snake_eater

LIBFT		=	libft/libft.a

MLX			= 	minilibx-linux/libmlx.a

INCL		=	$(addprefix -I , includes/)

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g

SANITIZE	=	-fsanitize=address -g

RM			=	rm -f

SRCS		=	srcs/parser.c					\
				srcs/main.c						\
				srcs/render.c					\
				srcs/render_textures.c			\
				srcs/render_background.c		\
				srcs/init.c						\
				srcs/game_commands.c			\
				srcs/game_actions.c				\
				srcs/exit.c						\
				srcs/exit_clean.c				\
				srcs/utils/utils.c				\
				srcs/utils/parsing_utils.c		\
	
OBJS		=	$(SRCS:.c=.o)

all:		$(LIBFT) $(MLX) $(NAME)

$(LIBFT):	
			@echo "\e[34mLIBFT COMPILATION...\e[0m"
			$(MAKE) -C "libft"

$(MLX):		
			@echo "\e[34mMINILIBX CONFIGURATION...\e[0m"
			@cd minilibx-linux && ./configure && make

$(NAME):	$(OBJS)
			@echo "\e[34mSO_LONG COMPILATION...\e[0m"
			$(CC) $(CFLAGS) $^ -L "libft" -L "minilibx-linux" -lmlx -lft -lXext -lX11 -lm -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

clean:
			$(RM) $(OBJS) 
			$(MAKE) clean -C "libft"

fclean:
			$(RM) $(OBJS) $(NAME) $(BONUS)
			$(MAKE) fclean -C "libft"

re:			fclean all

.PHONY:		all clean fclean re
