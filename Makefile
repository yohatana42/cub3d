NAME	= minishell
MAIN = srcs/main.c
SRCS	=
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
	$(CC) $(CFLAG) -o $(NAME) $(MAIN_OBJ) $(OBJS) -L$(LIBFT)

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

.PHONY: all clean fclean re
