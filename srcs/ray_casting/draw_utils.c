/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:33:39 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/21 07:12:06 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_color(t_direction side);

void	draw_roof(t_mlx_data *mlx_data, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		my_mlx_pixel_put(&mlx_data->img, x, y, 0xFFFFFF);
		y++;
	}
}

void	draw_floor(t_mlx_data *mlx_data, int x, int draw_end)
{
	int	y;

	y = draw_end;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&mlx_data->img, x, y, 0x000000);
		y++;
	}
}

void	draw_wall(t_mlx_data *mlx_data, int x, int draw_start, int draw_end)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		my_mlx_pixel_put(&mlx_data->img, x, y, get_color(mlx_data->ray->side));
		y++;
	}
}

static int	get_color(t_direction side)
{
	if (side == NORTH)
		return (0xCAE8E2);
	else if (side == SOUTH)
		return (0x00AE95);
	else if (side == WEST)
		return (0xE2B8CA);
	else
		return (0xE2E2B8);
}
