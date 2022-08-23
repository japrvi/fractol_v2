# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 18:08:51 by jpozuelo          #+#    #+#              #
#    Updated: 2022/08/23 20:10:58 by jpozuelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)
OBJS	=	$(SRCS:.c=.o)
CC		=	clang
RM		=	rm -rf
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address
NAME	=	fractol
MLX		=	./minilibx_opengl_20191021

all:	$(NAME)

clean:
		@$(MAKE) --directory=./minilibx_opengl_20191021 clean
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)

%.o:	%.c
	@$(MAKE) --directory=$(MLX) 
	@$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) -L$(MLX) -lmlx -framework OpenGL -framework AppKit  $(CFLAGS) -o $(NAME)

re: fclean all

.PHONY: all clean fclean re
