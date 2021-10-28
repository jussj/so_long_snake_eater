NAME		=	so_long

LIBFT		=	libft.a

INCL		=	$(addprefix -I , includes/)

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

SANITIZE	=	-fsanitize=address -g

RM			=	rm -f

SRCS		=	srcs/parser.c		\
				srcs/main.c			\
				srcs/render.c		\
				srcs/init.c			\
				srcs/game_cmd.c		\
				srcs/utils/utils.c	\
	
OBJS		=	$(SRCS:.c=.o)

all:		$(LIBFT) $(MLX) $(NAME)

$(LIBFT):	
			@echo "\e[34mLIBFT COMPILATION...\e[0m"
			$(MAKE) -C "libft"

$(MLX):		
			@echo "\e[34mMINILIBX COMPILATION...\e[0m"
			@cd minilibx-linux && make

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -L "libft" -L "minilibx-linux" -lmlx -lft -lbsd -lXext -lX11 -lm -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

clean:
			$(RM) $(OBJS) 
			$(MAKE) clean -C "libft"

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus 
