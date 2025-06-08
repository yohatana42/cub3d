/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:12:20 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 15:19:55 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
	{
		print_error("mlx_init failed. :(");
		exit(EXIT_FAILURE);
	}
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	if (!mlx_data->win)
	{
		free(mlx_data->mlx);
		print_error("mlx_new_windows failed. :(");
		exit(EXIT_FAILURE);
	}
}
