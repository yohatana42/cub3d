/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:18:34 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/08 15:21:11 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_mlx_data *mlx_data)
{
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.img, 0, 0);
	return (0);
}

int	close_window(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img.img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	free(mlx_data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
