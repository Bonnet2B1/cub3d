# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momox <momox@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 16:59:43 by edelarbr          #+#    #+#              #
#    Updated: 2024/02/05 15:15:08 by momox            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D

# ------------------------------ Sources -----------------------------

SRCS		:=	srcs/cub3d.c										\
				srcs/engine/game_display/game_display.c				\
				srcs/engine/game_display/get_color_coord.c			\
				srcs/engine/game_display/masks.c					\
				srcs/engine/game_display/put_assets.c				\
				srcs/engine/game_display/put_assets_two.c			\
				srcs/engine/ray_casting/horizontal_collusion.c		\
				srcs/engine/ray_casting/vertical_collusion.c		\
				srcs/engine/ray_casting/is_collision.c				\
				srcs/engine/ray_casting/ray_casting.c				\
				srcs/engine/ray_casting/draw_lazer.c				\
				srcs/engine/get_principal_measure.c					\
				srcs/engine/set_player_angle.c						\
				srcs/events/animation.c								\
				srcs/events/keyboard.c								\
				srcs/events/mouse.c									\
				srcs/events/player_actions.c						\
				srcs/events/player_movement.c						\
				srcs/events/player_rotation.c						\
				srcs/lib/ft_deg_to_rad.c							\
				srcs/lib/ft_isascii.c								\
				srcs/lib/ft_isdigit.c								\
				srcs/lib/ft_lstadd_back.c							\
				srcs/lib/ft_lstlast.c								\
				srcs/lib/ft_putstr_fd.c								\
				srcs/lib/ft_rad_to_deg.c							\
				srcs/lib/ft_split.c									\
				srcs/lib/ft_str_is_num.c							\
				srcs/lib/ft_strchr.c								\
				srcs/lib/ft_strdup.c								\
				srcs/lib/ft_strjoin.c								\
				srcs/lib/ft_strlen.c								\
				srcs/lib/ft_strncmp.c								\
				srcs/lib/ft_strncpy.c								\
				srcs/lib/ft_tabdup.c								\
				srcs/lib/ft_tablen.c								\
				srcs/lib/ft_trgb_colors.c							\
				srcs/minimap/create_imgs.c							\
				srcs/minimap/create_minimap.c						\
				srcs/minimap/find_minimap_img_size.c				\
				srcs/mlx/asset_to_image.c							\
				srcs/mlx/get_custom_assets.c						\
				srcs/mlx/get_dot_ber_assets.c						\
				srcs/mlx/load_assets.c								\
				srcs/mlx/loops.c									\
				srcs/other/exit_error.c								\
				srcs/other/free_n_exit.c							\
				srcs/other/init.c									\
				srcs/other/init_pt2.c								\
				srcs/other/x_memory.c								\
				srcs/parsing/check_file.c							\
				srcs/parsing/extract_data.c							\
				srcs/parsing/extract_file_to_tab.c					\
				srcs/parsing/fill_with_spaces.c						\
				srcs/parsing/format_error.c							\
				srcs/parsing/ft_atoi_mod.c							\
				srcs/parsing/parsing.c								\
				srcs/parsing/valid_way.c							\
				srcs/parsing/verify_map_chars.c						\

OBJ_DIR		:=	.objs
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ------------------------------ Flags -------------------------------

BREW		:=	$(shell brew --prefix)
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror -g3 -fsanitize=address
RM			:=	rm -rf

$(OBJ_DIR)/%.o :%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) $(INC_RL) -c $< -o $@

# ------------------------------ Colors ------------------------------

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m

# ------------------------------ Compilation -------------------------

all:			$(NAME)

$(NAME):		$(OBJS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME) $(OBJS) MLX42/build/libmlx42.a -I include -lglfw -L "$(BREW)/Cellar/glfw/3.3.9/lib/"
				@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"



# -------------------------------- Rules -----------------------------

clean:
				@ $(RM) $(OBJ_DIR)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME) $(RM)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all bonus clean fclean re
