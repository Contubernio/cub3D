# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albealva <albealva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 08:06:23 by gasroman          #+#    #+#              #
#    Updated: 2025/06/15 12:55:28 by albealva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================== VARIABLES =================================== #

FLAGS = -g -Wall -Wextra -Werror -fsanitize=address
RMV = rm -rf
CC = cc
NAME = cub3D

# =============================== MODE ======================================= #

BONUS = 0

# =============================== SOURCES ==================================== #

SRC_FILES = main.c \
			main_utils.c\
			parsing/count_map.c					\
			parsing/format_check.c				\
			parsing/is_surrounded.c				\
			parsing/line_checker.c				\
			parsing/store_color.c				\
			parsing/value_checks.c				\
			parsing_utils/free_data.c 			\
			parsing_utils/ft_double_realloc.c	\
			parsing_utils/ft_split_set.c		\
			parsing_utils/player_count.c		\
			parsing_utils/process_line.c		\
			parsing_utils/split_size.c			\
			parsing_utils/texture_color.c		\
			getnline/get_next_line.c			\
			getnline/get_next_line_utils.c		\
			draw/draw.c					\
			draw/frees.c			\
			draw/init_aux.c		\
			draw/init_game.c		\
			draw/init_game_2.c		\
			draw/init_images_texture.c		\
			draw/init_render.c		\
			draw/init_william.c		\
			draw/init.c		\
			draw/key_release.c		\
			draw/key.c		\
			draw/load_more.c		\
			draw/load.c		\
			draw/mini_william_aux.c		\
			draw/mini_william.c		\
			draw/minimap.c		\
			draw/mouse.c		\
			draw/move_william.c		\
			draw/move.c		\
			draw/render.c		\
			draw/render_aux.c		\
			draw/render_aux_v2.c		\
			draw/render_aux_v3.c		\
			draw/render_hud.c		\
			draw/update.c		\
			draw/update_hands.c		\
			draw/utils.c		\
			draw/worldmap.c		\
			P_PARSING_UTILS/utils.c\
			P_PARSING_UTILS/value_line.c\
			P_PARSING/init_parsing.c\
			P_PARSING/arguments.c\
			P_PARSING/file.c \
			P_PARSING/rgb.c \
			P_PARSING/extrac_element.c \
			P_PARSING/extrac_element_aux.c \
			P_PARSING/extract_element_aux_line.c \
			P_PARSING/extract_element_aux_hn.c \
			draw/clean_up.c \
			P_PARSING_UTILS/helpers.c \
			P_PARSING/build_map.c \
			P_PARSING/build_map_helper.c \
			P_PARSING/flood_fill.c \
			draw/render_mask.c \
			P_PARSING/parse_intro.c \
			draw/intro.c\
			draw/intro_aux.c\
			draw/render_hud_aux.c\
			draw/render_bonus.c\
			P_PARSING/flood_fill_aux.c\
			P_PARSING/borders.c\
			P_PARSING/borders_trasnform.c\
			P_PARSING/texture_player.c\
			P_PARSING_UTILS/init.c

LIB_PATH = ./libft/
LIB = $(LIB_PATH)libft.a

MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

INCLUDES = $(addprefix -I, inc)

# ============================== DIRECTORIES ================================= #

DIR_SOURCES = src/
DIR_OBJECTS = obj/

OBJECTS = $(addprefix $(DIR_OBJECTS), $(SRC_FILES:.c=.o))
DEPENDENCIES = $(addprefix $(DIR_OBJECTS), $(SRC_FILES:.c=.d))

# ============================== MAKE RULES ================================== #

all: dir $(NAME) $(MLX) $(LIB)

-include $(DEPENDENCIES)

dir:
	-mkdir -p $(DIR_OBJECTS)parsing
	-mkdir -p $(DIR_OBJECTS)parsing_utils
	-mkdir -p $(DIR_OBJECTS)P_PARSING
	-mkdir -p $(DIR_OBJECTS)P_PARSING_UTILS
	-mkdir -p $(DIR_OBJECTS)getnline
	-mkdir -p $(DIR_OBJECTS)draw 
	@$(MAKE) -C $(LIB_PATH)

$(DIR_OBJECTS)%.o: $(DIR_SOURCES)%.c
	$(CC) -MMD $(FLAGS) $(INCLUDES) -DBONUS=$(BONUS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -DBONUS=$(BONUS) $(OBJECTS) $(LIB) $(MLX) -lXext -lX11 -lm -o $(NAME)
	printf ":D\n"

bonus:
	make all BONUS=1

test:
	echo $(DIR_OBJECTS)
	echo $(DIR_SOURCE)
	echo $(DIR_INCLUDE)
	echo $(OBJECTS)
	echo $(DEPENDENCIES)

# ================================= CLEAN ==================================== #

clean:
	$(RMV) $(DIR_OBJECTS)
	printf "delete dir obj\n"

fclean: clean
	$(RMV) $(NAME)
	@$(MAKE) fclean -C $(LIB_PATH)
	printf "delete $(NAME)\n"

re: fclean all

.PHONY: all clean fclean dir bonus

.SILENT:
