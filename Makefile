# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:21:51 by rbarbier          #+#    #+#              #
#    Updated: 2023/11/29 18:18:38 by rbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
SO_LONG = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

OBJS_DIR = obj
OBJS_SUBS =	$(OBJS_DIR)
SRCS_DIR = srcs

MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = ./libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

FT_PRINTF_PATH = ./ft_printf/
FT_PRINTF_LIB = $(FT_PRINTF_PATH)libftprintf.a

SOURCES = map_check.c \
		main.c \
		print_error.c \
		read_map.c \
		map_possible.c \
		utils.c \
		tester.c

OBJECTS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

all: subsystems $(NAME) $(SO_LONG)

$(NAME) : $(OBJS_SUBS) $(OBJECTS)
	$(AR) -r $(NAME) $(OBJECTS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c inc/so_long.h Makefile
	@$(CC) $(CFLAGS) -I mlx -c $< -o $@

$(OBJS_DIR):
	-@mkdir $(OBJS_DIR)

subsystems:
	make -C $(MLX_PATH) all
	make bonus -C $(LIBFT_PATH) all
	make -C $(FT_PRINTF_PATH) all

$(SO_LONG) : $(LIBFT_LIB) $(MLX_LIB) $(FT_PRINTF_LIB) $(NAME)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(MLX_LIB) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(NAME) -o $@
	@rm -r $(NAME)

clean :
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@rm -fr $(OBJS_DIR)
	@rm -f $(NAME)

fclean : clean
#@make -C $(MLX_PATH) fclean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean
	@rm -f $(SO_LONG)

re: fclean all

.PHONY: all clean fclean re norm
