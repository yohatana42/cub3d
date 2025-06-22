/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:34:16 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/22 02:35:45 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_ray_data(t_ray_data *ray);

void	draw(t_mlx_data *mlx_data)
{
	init_ray_data(mlx_data->ray);
	render_next_frame(mlx_data);
	mlx_loop(mlx_data->mlx);
}

static void	init_ray_data(t_ray_data *ray)
{
	ray->pos.x = 7.0;
	ray->pos.y = 3.5;
	ray->dir.x = -1.0;
	ray->dir.y = 0.0;
	ray->plane.x = 0.0;
	ray->plane.y = 0.66;
}
