NAME		=	so_long

BONUS		=	so_long_bonus

LIBFT		=	libft.a

INCL		=	$(addprefix -I , includes/)

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

SANITIZE	=	-fsanitize=address -g

RM			=	rm -f

SRCS		=	srcs/parser.c					\
				srcs/main.c						\
				srcs/render.c					\
				srcs/render_clean.c				\
				srcs/render_textures.c			\
				srcs/render_background.c		\
				srcs/init.c						\
				srcs/game_commands.c			\
				srcs/game_actions.c				\
				srcs/utils/utils.c				\

SRCS_BONUS	= 	srcs/bonus/game_actions_bonus.c  	\
				srcs/bonus/parser_bonus.c			\
				srcs/bonus/render_bonus.c			\
				srcs/bonus/render_textures_bonus.c	\
				srcs/bonus/render_clean_bonus.c		\
				srcs/bonus/init_bonus.c				\
				srcs/main.c							\
				srcs/render_background.c			\
				srcs/game_commands.c				\
				srcs/utils/utils.c					\
	
OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

all:		$(LIBFT) $(MLX) $(NAME)

bonus:		$(LIBFT) $(MLX) $(BONUS)

$(LIBFT):	
			@echo "\e[34mLIBFT COMPILATION...\e[0m"
			$(MAKE) -C "libft"

$(MLX):		
			@echo "\e[34mMINILIBX COMPILATION...\e[0m"
			@cd minilibx-linux && ./configure && make

$(NAME):	$(OBJS)
			@echo "\e[34mSO_LONG COMPILATION...\e[0m"
			$(CC) $(CFLAGS) $^ -L "libft" -L "minilibx-linux" -lmlx -lft -lbsd -lXext -lX11 -lm -o $(NAME)

$(BONUS):	$(OBJS)
			@echo "\e[34mBONUS COMPILATION...\e[0m"
			$(CC) $(CFLAGS) $^ -L "libft" -L "minilibx-linux" -lmlx -lft -lbsd -lXext -lX11 -lm -o $(BONUS)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

clean:
			$(RM) $(OBJS) 
			$(MAKE) clean -C "libft"

fclean:		clean
			$(RM) $(NAME) $(BONUS)

re:			fclean all

.PHONY:		all clean fclean re bonus 
