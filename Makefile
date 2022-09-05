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
MLX		=	mlx_linux

all:	$(NAME)

clean:
		@$(MAKE) --directory=$(MLX) clean
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)

%.o:	%.c
	@$(MAKE) --directory=$(MLX) 
	@$(CC) $(CFLAGS) -I/usr/include -I$(MLX) -c $< -o $@

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -L$(MLX) -lmlx_Linux -L/usr/lib -I$(MLX) -lXext -lX11 -lm -lz -o $(NAME)

re: fclean all

.PHONY: all clean fclean re
