# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 16:21:20 by tcherepoff        #+#    #+#              #
#    Updated: 2025/10/18 10:46:19 by sbehar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS_PARSING	=	srcs/parsing/map.c				\
					srcs/parsing/lines.c			\
					srcs/parsing/key.c				\
					srcs/parsing/main_parsing.c		\
					srcs/parsing/player.c			\
					srcs/parsing/color.c			\
					srcs/parsing/loop.c				\
					srcs/parsing/checker_map.c		\
					srcs/parsing/checker_zero.c		\

SRCS_DRAW		=	srcs/draw/pixel.c				\
					srcs/draw/map.c					\
					srcs/draw/ray.c					\
					srcs/draw/dda.c					\
					srcs/draw/dda_init.c			\
					srcs/draw/setup.c				\
					srcs/draw/calc.c				\
					srcs/draw/render.c				\
					srcs/draw/texture.c				\
					srcs/draw/minimap.c				\
					srcs/draw/minimap_utils.c		\
					srcs/draw/minimap_setup.c		\
					srcs/draw/mouse.c				\

SRCS_UTILS		=	srcs/utils/calculate.c			\
					srcs/utils/check.c				\
					srcs/utils/free.c				\
					srcs/utils/print.c				\
					srcs/utils/transform.c			\
					srcs/utils/color.c				\
					main.c							\

SRCS = $(SRCS_PARSING) $(SRCS_UTILS) $(SRCS_DRAW)

OBJS = $(SRCS:.c=.o)
LDFLAGS	= -L./extern_files/mlx -lbsd -lmlx -lXext -lm -lX11
LDFLAG = ./extern_files/libft/libft.a
FLAG = -Wall -Werror -Wextra -Ilibft -Iincludes -Imlx -Ilibft/get_next_line -I.
# -Ofast
RM = @rm -f
AR = ar rcs
CC = gcc

.c.o:
			@$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@echo Congrats you compiling Libft !!
			@$(MAKE) -s -C ./extern_files/libft
			@echo Compiling MLX
			@$(MAKE) -s -C ./extern_files/mlx 2> /dev/null
			@echo Linking Objects
			@$(CC) $(FLAG) $(OBJS) $(LDFLAG) $(LDFLAGS) -o $(NAME)
			@echo That is Done!

all:		$(NAME)

clean:
			@echo Cleaning Libft
			@$(MAKE) clean -s -C ./extern_files/libft
			@echo Cleaning MLX
			@$(MAKE) clean -s -C ./extern_files/mlx
			@echo Cleaning Objects
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -s -C ./extern_files/libft
			@echo Cleaning $(NAME)
			$(RM) $(NAME)


re:			fclean all

rebonus: fclean
