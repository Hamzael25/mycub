
# Nom de l'exécutable
NAME = ./cub3D
NAME_SHORT = cub3D

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Affichage prompt
_CLEAR      = \033[0K\r\c
_OK         = [\033[32mOK\033[0m]

# Répertoires
SRC_DIR = srcs
OBJ_DIR = .objs
INC_DIR = includes
LIBFT_DIR = libft
MLX_DIR = mlx_linux

# Librairies
MLX_A = mlx_linux/libmlx.a
LIBFT_A = libft/libft.a

# Dépendances générales
HEADER = $(INC_DIR)/cub3d.h

# Chemins complets des fichiers source pour chaque sous-dossier
SRCS_PARSER = $(addprefix $(SRC_DIR)/parser/, file.c parsing.c variable.c)
SRCS_UTILS = $(addprefix $(SRC_DIR)/utils/, init.c free.c list.c parsing_utils.c)
SRCS_MAIN = $(addprefix $(SRC_DIR)/, main.c)

# Fichiers objets mandatory correspondants
OBJS_PARSER = $(patsubst $(SRC_DIR)/parser/%.c, $(OBJ_DIR)/parser/%.o, $(SRCS_PARSER))
OBJS_UTILS = $(patsubst $(SRC_DIR)/utils/%.c, $(OBJ_DIR)/utils/%.o, $(SRCS_UTILS))
OBJS_MAIN = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS_MAIN))

# Compilation et édition de liens
all: $(LIBFT_A) $(MLX_A) $(NAME)

# Règle pour construire l'exécutable
$(NAME): $(OBJS_UTILS) $(OBJS_PARSER) $(OBJS_MAIN)
	@$(CC) $(CFLAGS) $^ -o $@ -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lft -lXext -lX11 -lm
	@echo "$(_OK) $(NAME_SHORT) compiled"

# Construction des fichiers objets mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@echo "[..] $(NAME_SHORT)... compiling $*.c\r\c"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(_CLEAR)"

# Règle pour construire la libft et la mlxpour la version mandatory
$(LIBFT_A):
	@echo "[..] libft... compiling $*.c\r\c"
	@$(MAKE) -C $(LIBFT_DIR) -s
	@echo "$(_CLEAR)"

$(MLX_A):
	@echo "[..] mlx_linux... compiling $*.c\r\c"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(_CLEAR)"

# Règles de nettoyage
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
