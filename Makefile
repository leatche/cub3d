# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 16:21:20 by tcherepoff        #+#    #+#              #
#    Updated: 2025/08/11 18:39:42 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS_PARSING	=	srcs/parsing/analyse_map.c		\
					srcs/parsing/map.c				\
					srcs/parsing/main_parsing.c		\
					srcs/parsing/player.c			\

SRCS_UTILS		=	srcs/utils/calculate.c			\
					srcs/utils/check.c				\
					srcs/utils/print.c				\
					srcs/utils/transform.c			\
					main.c							\

SRCS = $(SRCS_PARSING) $(SRCS_UTILS)

OBJS = $(SRCS:.c=.o)
# LDFLAGS	= -Lmlx -lbsd -lmlx -lXext -lX11
LDFLAG = ./extern_files/libft/libft.a
FLAG = -Wall -Werror -Wextra -Ilibft -Iincludes -Ilibft/get_next_line -I. -fsanitize=address -g3
# -Imlx 
RM = @rm -f
AR = ar rcs
CC = gcc

.c.o:
			@$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@echo Congrats you compiling Libft !!
			@$(MAKE) -s -C ./extern_files/libft
# 			@echo Compiling MLX
# 			@$(MAKE) -s -C ./extern_files/mlx 2> /dev/null
			@echo Linking Objects
			@$(CC) $(FLAG) $(OBJS) $(LDFLAG)  -o $(NAME)
# 			$(LDFLAGS)
			@echo That is Done!

all:		$(NAME)

clean:
			@echo Cleaning Libft
			@$(MAKE) clean -s -C ./extern_files/libft
# 			@echo Cleaning MLX
# 			@$(MAKE) clean -s -C ./mlx
			@echo Cleaning Objects
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -s -C ./extern_files/libft
			@echo Cleaning $(NAME)
			$(RM) $(NAME)


re:			fclean all

rebonus: fclean
