# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 18:08:51 by jpozuelo          #+#    #+#              #
#    Updated: 2022/09/08 18:06:25 by jpozuelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard *.c)
OBJS	=	$(SRCS:.c=.o)
CC		=	clang
RM		=	rm -rf
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -O3
NAME	=	fractol
MLX		=	mlx

all:	$(NAME)

clean:
		@$(MAKE) --directory=$(MLX) clean
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)

%.o:	%.c
	@$(MAKE) --directory=$(MLX) 
	@$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all

.PHONY: all clean fclean re
