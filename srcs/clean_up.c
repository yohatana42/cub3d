/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:15:26 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/22 03:29:03 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	destroy_textures(t_mlx_data *mlx_data);

int	clean_up(t_mlx_data *mlx_data)
{
	destroy_textures(mlx_data);
	clean_map_data(mlx_data->map_data);
	close_window(mlx_data);
	return (0);
}

static void	destroy_textures(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->north_tex.img.img);
	mlx_destroy_image(mlx_data->mlx, mlx_data->south_tex.img.img);
	mlx_destroy_image(mlx_data->mlx, mlx_data->west_tex.img.img);
	mlx_destroy_image(mlx_data->mlx, mlx_data->east_tex.img.img);
}
