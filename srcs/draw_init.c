/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:13:44 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 15:33:55 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_init(t_mlx_data *mlx_data, t_map_data *map_data)
{
	mlx_data->img.img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	if (!mlx_data->img.img)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		print_error("mlx_new_image failed. :(");
		exit(EXIT_FAILURE);
	}
	mlx_data->img.addr = mlx_get_data_addr(
		mlx_data->img.img,
		&mlx_data->img.bits_per_pixel,
		&mlx_data->img.line_length,
		&mlx_data->img.endian
	);
	(void)map_data;
}
