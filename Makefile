
NAME = so_long

SRC = draw_utils.c get_next_line.c get_next_line_utils.c \
	  parse_map.c parse_map_2.c player_movs.c so_long.c \
	  utils.c utils_2.c

OBJS = ${SRC:%.c=%.o}

MLX = libmlx.dylib

CC = cc -Wall -Werror -Wextra

RM = rm -f

%.o:		%.c so_long.h
			$(CC) -Imlx -c $< -o $@

all:		$(NAME)

$(NAME):	$(MLX) $(OBJS)
			$(CC) -L mlx/ -lmlx $(OBJS) -o $(NAME)

$(MLX):
			@make -C mlx/
			@cp mlx/$(MLX) $(MLX)
clean:
			@$(RM) $(OBJS) $(MLX)
			@make clean -C mlx/
			@make clean -f Makefile_bonus

fclean:		clean
			$(RM) $(NAME)
			@make fclean -f Makefile_bonus

re: 		fclean all

bonus:
			@make -f Makefile_bonus

.PHONY: clean fclean re all bonus