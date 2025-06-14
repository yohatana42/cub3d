NAME	= cub3d
MAIN	= srcs/main.c
SRCS	= 	srcs/init_data.c\
			srcs/error.c\
			srcs/mlx_event.c\
			srcs/init_mlx.c\
			srcs/draw_init.c\
			srcs/clean_up.c\
			srcs/validate_map.c\
			srcs/mlx_utils.c\
			srcs/draw.c\
			srcs/read_map_file.c\
			get_next_line/get_next_line_utils.c\
			get_next_line/get_next_line.c\
			srcs/debug.c
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
	$(CC) $(CFLAG) -o $(NAME) $(MAIN_OBJ) $(OBJS) -L$(LIBFT) -lft -L$(MINILIBX_DIR) -lmlx -lm -lXext -lX11

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
	norminette srcs/*.c includes/*.h

.PHONY: all clean fclean re
