NAME	= cub3d
MAIN	= srcs/main.c
SRCS	= 	srcs/init_data/init_data.c\
			srcs/init_data/init_data_util.c\
			srcs/init_data/set_player.c\
			srcs/init_data/set_map.c\
			srcs/error.c\
			srcs/mlx_event.c\
			srcs/init_mlx.c\
			srcs/draw_init.c\
			srcs/clean_up.c\
			srcs/validate_infile.c\
			srcs/read_map_file.c\
			srcs/mlx_utils.c\
			srcs/draw.c\
			srcs/ray_casting/ray_casting.c\
			srcs/ray_casting/calculation_utils.c\
			srcs/ray_casting/dda.c\
			srcs/ray_casting/draw_utils.c\
			srcs/keyhook_utils/arrow.c\
			srcs/keyhook_utils/wasd.c\
			get_next_line/get_next_line_utils.c\
			get_next_line/get_next_line.c\
			srcs/validate_infile_util.c\
			srcs/validate_infile_format.c\
			srcs/debug.c\
			srcs/validate_line_format.c\
			srcs/validate_map.c\
			srcs/validate_wall.c\
			srcs/search_wall.c\
			srcs/util.c\
			srcs/dfs.c
HEADERS	= \
	includes/cub3d.h
MAIN_OBJ = $(MAIN:.c=.o)
OBJS	= $(SRCS:.c=.o)

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I includes/

.DEFAULT:	all

all: $(NAME)

# libft
LIBFT = libft
$(LIBFT)/libft.a:
	make -C $(LIBFT)

# minilibX
MINILIBX_DIR = minilibx-linux
$(MINILIBX_DIR)/libmlx_Linux.a:
	make -C $(MINILIBX_DIR)

$(NAME): $(MAIN_OBJ) $(OBJS) $(LIBFT)/libft.a $(MINILIBX_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJS) -L$(LIBFT) -lft -L$(MINILIBX_DIR) -lmlx -lm -lXext -lX11

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT) clean
	make -C $(MINILIBX_DIR) clean
	rm -f $(MAIN_OBJ) $(OBJS)

fclean: clean
	make -C $(LIBFT) fclean
	make -C $(MINILIBX_DIR) clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette srcs includes

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./cub3d maps/test.cub

.PHONY: all clean fclean re norm valgrind
