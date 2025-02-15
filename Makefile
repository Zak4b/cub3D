NAME = cub3D

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[0;33m
RESET = \033[0m

LIBFT = libft/libft.a
MLX_FOLDER = minilibx-linux
MLX = $(MLX_FOLDER)/libmlx.a

FLAGS = -Wall -Wextra -Werror -g -O3
INC = -I./$(MLX_FOLDER) -I./libft -I./includes
LIB = -L./$(MLX_FOLDER) -lmlx -lXext -lX11 -lm -lz -L./libft/ -lft
SRCDIR = srcs
OBJDIR = obj

SOURCES = ./events/events.c ./events/events2.c ./events/hooks.c ./lines.c ./main.c ./mlx_utils/img_utils.c ./mlx_utils/img_utils2.c ./mlx_utils/mlx_utils.c ./parsing/parsing.c ./parsing/parsing2.c ./parsing/parsing_utils.c ./raycasting/raycasting.c ./raycasting/raycasting_utils.c ./render/color.c ./render/render_background.c ./render/render_walls.c ./utils/clamp.c ./utils/ft_puterror.c ./utils/ft_strchrs.c ./utils/line_dup.c 
	
OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@cc $(FLAGS) $(OBJS) -o $(NAME) $(INC) $(LIB)
	@echo "$(GREEN)Compilation finished successfully!$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Building Libft...$(RESET)"
	@make -s -C libft libft.a

$(MLX):
	@echo "$(GREEN)Building minilibx...$(RESET)"
	@make -s -C $(MLX_FOLDER) all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(FLAGS) $(INC) -c $< -o $@

norm:
	@echo "Lancement de la norminette..."
	@norminette | grep "Error" > norm_errors.log || true
	@if [ -s norm_errors.log ]; then \
		err_count=$$(wc -l < norm_errors.log); \
		echo "$(RED)$$err_count erreur(s) détectée(s) :$(RESET)"; \
		cat norm_errors.log; \
	else \
		echo "$(GREEN)OK - Aucun problème détecté par la norminette.$(RESET)"; \
	fi
	@rm norm_errors.log

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)
	@make -s -C libft clean

fclean: clean
	@echo "$(RED)Cleaning all...$(RESET)"
	@rm -f $(NAME)
	@make -s -C $(MLX_FOLDER) clean
	@make -s -C libft fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
