CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L minilibx-linux -lmlx -lX11 -lXext -lm

NAME = cub3D

LIBFT_DIR = libft

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

SRC_DIR = src
OBJ_DIR = obj

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m

SRC = $(LIBFT_DIR)/ft_atoi.c				\
      $(LIBFT_DIR)/ft_isspace.c				\
      $(LIBFT_DIR)/ft_split.c				\
      $(LIBFT_DIR)/ft_strcdup.c				\
      $(LIBFT_DIR)/ft_strchr.c				\
      $(LIBFT_DIR)/ft_strcmp.c				\
      $(LIBFT_DIR)/ft_strdup.c				\
      $(LIBFT_DIR)/ft_strjoin.c				\
      $(LIBFT_DIR)/ft_strlen.c				\
      $(LIBFT_DIR)/ft_strncmp.c				\
      $(LIBFT_DIR)/ft_strrchr.c				\
      $(LIBFT_DIR)/ft_substr.c				\
      $(LIBFT_DIR)/get_next_line_utils.c	\
      $(LIBFT_DIR)/get_next_line.c			\
      $(SRC_DIR)/parsing/check_attributes.c	\
      $(SRC_DIR)/parsing/extract_content.c	\
      $(SRC_DIR)/parsing/extract_grid.c		\
      $(SRC_DIR)/parsing/parse_attributes.c	\
      $(SRC_DIR)/parsing/validate_file.c	\
      $(SRC_DIR)/parsing/validate_map.c		\
      $(SRC_DIR)/render/draw.c				\
      $(SRC_DIR)/render/init_game.c			\
      $(SRC_DIR)/render/load_textures.c		\
      $(SRC_DIR)/render/move_player.c		\
      $(SRC_DIR)/render/raycasting.c		\
      $(SRC_DIR)/render/set_player_dir.c	\
      $(SRC_DIR)/render/update_player.c		\
      $(SRC_DIR)/utils/free_array.c			\
      $(SRC_DIR)/utils/free_map.c			\
      $(SRC_DIR)/utils/is_attribute.c		\
      $(SRC_DIR)/utils/keyboard.c			\
      $(SRC_DIR)/utils/check_line.c			\
      $(SRC_DIR)/main.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)Cub3D compiled$(RESET)"

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/libft
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/render
	@mkdir -p $(OBJ_DIR)/utils

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@echo "$(YELLOW)Object files removed$(RESET)"

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@echo "$(RED)Object and executable files removed$(RESET)"

re: fclean all

usage:
	@echo "$(YELLOW)"
	@echo "./Cub3D path_to_map.cub"
	@echo
	@echo "NO path_to_the_north_texture.xpm"
	@echo "SO path_to_the_south_texture.xpm"
	@echo "EA path_to_the_east_texture.xpm"
	@echo "WE path_to_the_west_texture.xpm"
	@echo
	@echo "F R,G,B"
	@echo "C R,G,B"
	@echo
	@echo "11111"
	@echo "10001"
	@echo "10N01"
	@echo "10001"
	@echo "11111"
	@echo "$(RESET)"

.PHONY: all mlx clean fclean re usage
