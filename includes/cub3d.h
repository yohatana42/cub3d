/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:04:14 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/20 21:14:17 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define WINDOW_NAME "cub3d"
# define WIDTH 960
# define HEIGHT 540
# define BIT_FLG_1 1
# define BIT_FLG_2 2
# define BIT_FLG_4 4
# define BIT_FLG_8 8

typedef struct s_line	t_line;

enum
{
	ON_DESTROY = 17
};

typedef struct s_line
{
	char	*str;
	t_line	*next;
}	t_line;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_ray_data
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	t_vec	ray_dir;
	t_vec	map;
	t_vec	step;
	t_vec	side_dist;
	t_vec	delta_dist;
	int		side;
	double	camera_x;
	double	wall_dist;
}	t_ray_data;

typedef struct s_map_data
{
	char	**map;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	t_color	*roof;
	t_color	*floor;
}	t_map_data;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_img_data	img;
	t_ray_data	ray;
	t_map_data	map_data;
}	t_mlx_data;

t_line		**read_map_file(char *map_file, t_line **head);
void		init_data(t_line **head, t_map_data *data, t_mlx_data *malx_data);
void		clean_up(t_mlx_data *mlx_data, t_map_data *data);
void		draw_init(t_mlx_data *mlx_data, t_map_data *data);
void		draw(t_mlx_data *mlx_data, t_map_data *map_data);
void		init_mlx(t_mlx_data *mlx_data);
void		mlx_event(t_mlx_data *mlx_data, t_map_data *data);
void		free_line_list(t_line **head);

// validate
void		validate_infile(t_line **head);
void		validate_infile_format(t_line **head);
void		validate_line_format(t_line **head);

// validate infile
int			count_line_list(t_line **head);
void		exit_error_infile_format(char *str, t_line **head);

// validate_infile_util
bool		is_texture(char *line);
bool		is_color(char *line);
bool		is_map(char *line);

// error
void		print_error(char *str);
void		exit_error(char *str);

// mlx_utils
void		my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int			render_next_frame(t_mlx_data *mlx_data);
int			close_window(t_mlx_data *mlx_data);
int			key_hook(int keycode, t_mlx_data *mlx_data);

// util
int			count_double_array(char **str);
void		free_double_array(char **str);

// debug
void		print_line_list(t_line **head);

#endif
