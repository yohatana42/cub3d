/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:12:20 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/22 16:35:44 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_texture(t_mlx_data *mlx_data, t_texture *tex, char *path);

void	init_mlx(t_mlx_data *mlx_data)
{
	t_map_data	*map_data;

	map_data = mlx_data->map_data;
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		exit_error("mlx_init failed. :(");
	load_texture(mlx_data, &mlx_data->north_tex, map_data->north_path);
	load_texture(mlx_data, &mlx_data->south_tex, map_data->south_path);
	load_texture(mlx_data, &mlx_data->west_tex, map_data->west_path);
	load_texture(mlx_data, &mlx_data->east_tex, map_data->east_path);
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	if (!mlx_data->win)
	{
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
		clean_map_data(mlx_data->map_data);
		exit_error("mlx_new_windows failed. :(");
	}
}

static void	load_texture(t_mlx_data *mlx_data, t_texture *tex, char *path)
{
	tex->img.img = mlx_xpm_file_to_image(
			mlx_data->mlx,
			path,
			&tex->width,
			&tex->height);
	if (!tex->img.img)
	{
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
		clean_map_data(mlx_data->map_data);
		exit_error("failed: load texture");
	}
	tex->img.addr = mlx_get_data_addr(
			tex->img.img,
			&tex->img.bits_per_pixel,
			&tex->img.line_length,
			&tex->img.endian);
}
