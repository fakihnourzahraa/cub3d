# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nour <nour@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 17:23:49 by nfakih            #+#    #+#              #
#    Updated: 2026/01/27 10:38:30 by nour             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = cub3D

SRC = main.c raycasting/moves.c raycasting/calculations.c mlx.c\
 get_next_line/get_next_line_bonus.c \
 ft_printf/ft_printf.c ft_printf/ft_putchar_fd.c \
 ft_printf/ft_putnbr_base.c ft_printf/ft_putstr_fd.c Libft/ft_atoi.c \
 Libft/ft_itoa.c Libft/ft_memset.c Libft/ft_putendl_fd.c Libft/ft_split.c \
 Libft/ft_strchr.c Libft/ft_strdup.c Libft/ft_strjoin.c Libft/ft_strcmp.c\
 Libft/ft_strlcat.c Libft/ft_strlcpy.c Libft/ft_strlen.c Libft/ft_isdigit.c \
 Libft/ft_strncmp.c Libft/ft_strnstr.c Libft/ft_strrchr.c \
 Libft/ft_strstr.c Libft/ft_strtrim.c Libft/ft_substr.c Libft/ft_atoi_safe.c\
 raycasting/DDA.c raycasting/drawing.c raycasting/initial.c \
 data_structures/cleanup1.c data_structures/data_structures.c \
 data_structures/fake_map.c data_structures/cleanup2.c \
 raycasting/rotations.c\
 parsing/error_handle.c parsing/helped.c parsing/parse_utils.c \
 parsing/parse_utils2.c parsing/parse.c parsing/parse_texture.c \
 parsing/parse_color.c parsing/parse_map.c parsing/map_utils.c \
 parsing/validate_map.c parsing/flood_fills.c parsing/combine.c\
 parsing/map_help.c raycasting/drawing_single.c\
 parsing/combine2.c\

OBJ	= $(SRC:.c=.o)

CC      = cc -Wall -Werror -Wextra
CFLAGS  =  -Iminilibx-linux -g -Ift_printf -Iget_next_line -ILibft

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(MLX_LIB):
	@echo "🎨 Building MinilibX..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo "🏂 done making MinilibX"

$(NAME): $(MLX_LIB) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
	@echo "🏂 done making $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@echo "💄 done cleaning"

fclean: clean
	@rm -f $(NAME)
	@echo "👺 done fcleaning"

re: fclean all

ex: all clean

.PHONY: all clean fclean re