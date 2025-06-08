/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:04:14 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 15:45:07 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
// # include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

typedef struct s_line	t_line;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_data
{
	char	**map;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	t_color	*roof;
	t_color	*floor;
}	t_data;

typedef struct s_mlx_data
{
	// t_mlx	*mlx;
}	t_mlx_data;

typedef struct s_line
{
	char	*str;
	t_line	*next;
}	t_line;

void	init_data(char *map_name, t_data *data);
void	validation_map(t_data *data);
void	clean_up(t_mlx_data *mlx_data, t_data *data);
void	draw_init(t_mlx_data *mlx_data, t_data *data);
void	init_mlx(t_mlx_data *mlx_data, t_data *data);
void	mlx_event(t_mlx_data *mlx_data, t_data *data);

// error
void	print_error(char *str);
void	exit_error(char *str);

#endif
