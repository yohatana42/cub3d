/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:02:25 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/22 03:23:34 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		draw_wall_line(t_mlx_data *mlx_data, int x, t_ray_data *ray);

void	ray_casting(t_mlx_data *mlx_data, t_map_data *map_data)
{
	t_ray_data	*ray;
	int			x;

	ray = mlx_data->ray;
	x = 0;
	while (x < WIDTH)
	{
		ray->camera_x = 2 * x / (double)WIDTH - 1;
		calculate_ray_direction(ray);
		ray->map.x = (int)(ray->pos.x);
		ray->map.y = (int)(ray->pos.y);
		calculate_delta_distances(ray);
		calculate_step_and_side_dist(ray);
		perform_dda(ray, map_data);
		calculate_wall_distance(ray);
		draw_wall_line(mlx_data, x, ray);
		x++;
	}
}

static void	draw_wall_line(t_mlx_data *mlx_data, int x, t_ray_data *ray)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(HEIGHT / ray->wall_dist);
	draw_start = HEIGHT / 2 - line_height / 2;
	draw_end = HEIGHT / 2 + line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	draw_ceiling(mlx_data, x, draw_start);
	draw_wall(mlx_data, x, draw_start, draw_end);
	draw_floor(mlx_data, x, draw_end);
}
