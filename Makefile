# Color
RESET	= \033[0m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m

# Standard
NAME	=	solong

# Compiler and Flags
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
RM	=	rm -f

# Directories
INC		=	-I includes/ -I ./libft -I ./minilibx-linux
SRC_DIR =	srcs/
OBJ_DIR	=	obj/
LIBFT	=	libft/libft.a
MLX 	=	minilibx-linux/libmlx_Linux.a

# Sources Files

SRCS	=	$(SRC_DIR)die.c\
			$(SRC_DIR)so_long.c\
			$(SRC_DIR)map_init.c\
			$(SRC_DIR)root_init.c\
			$(SRC_DIR)map_read.c\
			$(SRC_DIR)map_width.c\
			$(SRC_DIR)game_init.c\
			$(SRC_DIR)map_height.c\
			$(SRC_DIR)map_isvalid.c\
			$(SRC_DIR)game_destroy.c\
			$(SRC_DIR)root_destroy.c\
			$(SRC_DIR)map_parsing.c\
			$(SRC_DIR)draw.c\
			$(SRC_DIR)mlx_utils.c\
			$(SRC_DIR)event.c\
			$(SRC_DIR)update.c\
			$(SRC_DIR)move_player.c\
			$(SRC_DIR)map_getcoord.c\
			$(SRC_DIR)is_valid_path.c
OBJ	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build Rules
all: $(MLX) $(NAME) $(LIBFT)

$(MLX):
			@echo "\n [ $(YELLOW)..$(RESET) ] | $(RED)Compiling minilibx..$(RESET)\n"
			make -C minilibx-linux
			@echo "\n [ $(GREEN)OK $(RESET)] | $(GREEN)Minilibx ready!$(RESET)\n"

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

			@echo "\n [ $(YELLOW)$(NAME) $(RESET)] $(GREEN)has been created!$(RESET)\n"

$(LIBFT):
			@echo "\n [ $(YELLOW)..$(RESET) ] | $(RED)Compiling libft..$(RESET)\n"
			make -C ./libft
			@echo "\n [ $(GREEN)OK $(RESET)] | $(GREEN)Libft ready!$(RESET)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
#	@echo "Creating $(@D)/ $(@F)"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -I/usr/include -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C libft
	make clean -C minilibx-linux
	@echo "\n$(BLUE)object files removed.$(RESET)\n"


fclean: clean
	$(RM)  $(NAME)
	make fclean -C libft
	@echo "\n$(BLUE)binary file removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
