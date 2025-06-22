/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:34:16 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/22 04:02:28 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_ray_data(t_ray_data *ray, t_map_data *map_data);
static void	set_north_south(t_ray_data *ray, int is_south);
static void	set_west_east(t_ray_data *ray, int is_east);

void	draw(t_mlx_data *mlx_data)
{
	init_ray_data(mlx_data->ray, mlx_data->map_data);
	render_next_frame(mlx_data);
	mlx_loop(mlx_data->mlx);
}

static void	init_ray_data(t_ray_data *ray, t_map_data *map_data)
{
	ray->pos.x = map_data->player_pos.x;
	ray->pos.y = map_data->player_pos.y;
	if (map_data->player_dir == NORTH || map_data->player_dir == SOUTH)
		set_north_south(ray, map_data->player_dir == SOUTH);
	else
		set_west_east(ray, map_data->player_dir == EAST);
}

static void	set_north_south(t_ray_data *ray, int is_south)
{
	ray->dir.x = 0.0;
	ray->dir.y = -1.0 + (2.0 * is_south);
	ray->plane.x = 0.66 - (1.32 * is_south);
	ray->plane.y = 0.0;
}

static void	set_west_east(t_ray_data *ray, int is_east)
{
	ray->dir.x = -1.0 + (2.0 * is_east);
	ray->dir.y = 0.0;
	ray->plane.x = 0.0;
	ray->plane.y = 0.66 - (1.32 * is_east);
}
