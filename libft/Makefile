# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 15:48:42 by jusaint-          #+#    #+#              #
#    Updated: 2020/12/17 21:18:59 by jusaint-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC		= gcc

CFLAGS		= -Wall -Wextra -Werror

RM		= rm -f

SRCS		= ft_memset.c		\
		  ft_bzero.c		\
		  ft_memcpy.c		\
	  	  ft_memccpy.c		\
		  ft_memmove.c 		\
		  ft_memchr.c		\
		  ft_memcmp.c		\
		  ft_strlen.c		\
		  ft_isdigit.c		\
		  ft_isalpha.c		\
		  ft_isascii.c		\
		  ft_isalnum.c		\
		  ft_isprint.c		\
		  ft_toupper.c		\
		  ft_tolower.c		\
		  ft_strchr.c		\
		  ft_strrchr.c		\
		  ft_strncmp.c		\
		  ft_strlcpy.c		\
		  ft_strlcat.c		\
		  ft_strnstr.c		\
		  ft_atoi.c		\
		  ft_calloc.c		\
		  ft_strdup.c		\
		  ft_substr.c		\
		  ft_strjoin.c		\
		  ft_strtrim.c		\
		  ft_split.c		\
		  ft_itoa.c		\
		  ft_strmapi.c		\
		  ft_putchar_fd.c	\
		  ft_putstr_fd.c	\
		  ft_putendl_fd.c	\
		  ft_putnbr_fd.c	\
		  ft_putnbr_base.c	\
		  ft_lstnew.c		\
		  ft_lstadd_front.c	\
		  ft_lstsize.c		\
		  ft_lstlast.c		\
		  ft_lstadd_back.c	\
		  ft_lstdelone.c	\
		  ft_lstclear.c		\
		  ft_lstiter.c		\
		  get_next_line.c	\
		  ft_putstr_len.c	\
		  ft_nblen_base.c	\
		  ft_atoi_base.c	\
		  ft_iswhitespace.c	\
		  ft_free_malloc.c	\


OBJS		= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re bonus
