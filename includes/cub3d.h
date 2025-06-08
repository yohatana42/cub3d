/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:04:14 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 15:46:27 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
// # include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

# define WINDOW_NAME "cub3d"
# define WIDTH 960
# define HEIGHT 540

enum
{
	ON_DESTROY = 17
};

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

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

typedef struct	s_img_data {
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
}	t_mlx_data;

void	init_data(char *map_name, t_map_data *data);
void	validation_map(t_map_data *data);
void	clean_up(t_mlx_data *mlx_data, t_map_data *data);
void	draw_init(t_mlx_data *mlx_data, t_map_data *data);
void	draw(t_mlx_data *mlx_data, t_map_data *map_data);
void	init_mlx(t_mlx_data *mlx_data);
void	mlx_event(t_mlx_data *mlx_data, t_map_data *data);

// error
void	print_error(char *str);
void	exit_error(char *str);

// mlx_utils
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int		render_next_frame(t_mlx_data *mlx_data);
int		close_window(t_mlx_data *mlx_data);
int		key_hook(int keycode, t_mlx_data *mlx_data);

#endif
