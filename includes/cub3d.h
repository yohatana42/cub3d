/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:04:14 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 13:59:59 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

typedef struct s_data
{
	char	**map;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*roof;
	char	*floor;
}	t_data;

typedef struct s_mlx_data
{
	// t_mlx	*mlx;
}	t_mlx_data;

void	init_data(char *map_name, t_data *data);

// error
void	print_error(char *str);
void	exit_error(char *str);

#endif
