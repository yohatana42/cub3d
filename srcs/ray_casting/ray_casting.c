/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:02:25 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/20 15:04:11 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		get_color(int side);
static void		draw_wall_line(t_mlx_data *mlx_data, int x, t_ray_data *ray);

void	ray_casting(t_mlx_data *mlx_data, t_map_data *map_data)
{
	(void)map_data;
	t_ray_data	*ray;
	int			x;
	int world_map[8][8] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};

	ray = mlx_data->ray;
	printf("RAY: %f, %f\n", mlx_data->ray->pos.x, mlx_data->ray->pos.y);
	x = 0;
	while (x < WIDTH)
	{
		ray->camera_x = 2 * x / (double)WIDTH - 1;
		calculate_ray_direction(ray);
		ray->map.x = (int)(ray->pos.x);
		ray->map.y = (int)(ray->pos.y);
		calculate_delta_distances(ray);
		calculate_step_and_side_dist(ray);
		perform_dda(ray, world_map);
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
	int	y;

	line_height = (int)(HEIGHT / ray->wall_dist);
	draw_start = HEIGHT / 2 - line_height / 2;
	draw_end = HEIGHT / 2 + line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	y = 0;
	while (y < draw_start)
	{
		my_mlx_pixel_put(&mlx_data->img, x, y, 0xFFFFFF);
		y++;
	}
	y = draw_start;
	while (y <= draw_end)
	{
		my_mlx_pixel_put(&mlx_data->img, x, y, get_color(ray->side));
		y++;
	}
	while (y < HEIGHT - 1)
	{
		my_mlx_pixel_put(&mlx_data->img, x, y, 0xFFFFFF);
		y++;
	}
}

static int	get_color(int side)
{
	if (side == 0)
		return (0xCAE8E2);
	else
		return (0x00AE95);
}
