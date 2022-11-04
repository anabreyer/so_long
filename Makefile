NAME		=	so_long

CC			=	clang

FLAG		=	-Wall -Wextra -Werror

LIBFT_PATH	=	./libft/

PRINTF_PATH = 	./ft_printf/

LIBFT_FILE	=	libft.a

PRINTF_FILE = 	libftprintf.a

MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

PRINTF_LIB	=	$(addprefix $(PRINTF_PATH), $(PRINTF_FILE))

MLX_FLAG	=	-lXext -lX11

MLX_PATH	=	./mlx/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	map.c				\
				map_checker.c		\
				render.c			\
				render_mouv.c		\
				set.c				\
				texture.c			\
				utils.c				\
				main.c

SRC_DIR		=	./src/

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	@make -C $(LIBFT_PATH)
	@make -C $(PRINTF_PATH)

mlx:
	@make -C mlx

$(NAME): lib mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(PRINTF_LIB) $(MLX_EX) -o $(NAME)

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(PRINTF_PATH)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re
