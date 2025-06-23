/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:18:46 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/23 08:45:26 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	check_collision(t_mlx_data *mlx_data, t_vec new_pos);

void	move_forward(t_mlx_data *mlx_data)
{
	t_ray_data	*ray;
	t_vec		new_pos;

	ray = mlx_data->ray;
	new_pos.x = ray->pos.x + ray->dir.x * 0.1;
	new_pos.y = ray->pos.y + ray->dir.y * 0.1;
	if (check_collision(mlx_data, new_pos))
		return ;
	ray->pos.x = new_pos.x;
	ray->pos.y = new_pos.y;
}

void	move_backward(t_mlx_data *mlx_data)
{
	t_ray_data	*ray;
	t_vec		new_pos;

	ray = mlx_data->ray;
	new_pos.x = ray->pos.x - ray->dir.x * 0.1;
	new_pos.y = ray->pos.y - ray->dir.y * 0.1;
	if (check_collision(mlx_data, new_pos))
		return ;
	ray->pos.x = new_pos.x;
	ray->pos.y = new_pos.y;
}

void	move_left(t_mlx_data *mlx_data)
{
	t_ray_data	*ray;
	t_vec		new_pos;

	ray = mlx_data->ray;
	new_pos.x = ray->pos.x + ray->dir.y * 0.1;
	new_pos.y = ray->pos.y - ray->dir.x * 0.1;
	if (check_collision(mlx_data, new_pos))
		return ;
	ray->pos.x = new_pos.x;
	ray->pos.y = new_pos.y;
}

void	move_right(t_mlx_data *mlx_data)
{
	t_ray_data	*ray;
	t_vec		new_pos;

	ray = mlx_data->ray;
	new_pos.x = ray->pos.x - ray->dir.y * 0.1;
	new_pos.y = ray->pos.y + ray->dir.x * 0.1;
	if (check_collision(mlx_data, new_pos))
		return ;
	ray->pos.x = new_pos.x;
	ray->pos.y = new_pos.y;
}

static bool	check_collision(t_mlx_data *mlx_data, t_vec new_pos)
{
	t_vec	map_min;
	t_vec	map_max;
	int		x;
	int		y;

	map_min.x = (int)(new_pos.x - 0.3);
	map_max.x = (int)(new_pos.x + 0.3);
	map_min.y = (int)(new_pos.y - 0.3);
	map_max.y = (int)(new_pos.y + 0.3);
	y = map_min.y;
	while (y <= map_max.y)
	{
		x = map_min.x;
		while (x <= map_max.x)
		{
			if (y < 0 || y >= (int)mlx_data->map_data->height
				|| x < 0 || x >= (int)mlx_data->map_data->width)
				return (true);
			if (mlx_data->map_data->map[y][x] == '1')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}
