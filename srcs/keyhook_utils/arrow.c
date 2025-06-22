/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:22:24 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/22 04:03:09 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_right(t_ray_data *ray)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir.x;
	old_plane_x = ray->plane.x;
	ray->dir.x = ray->dir.x * cos(0.1) - ray->dir.y * sin(0.1);
	ray->dir.y = old_dir_x * sin(0.1) + ray->dir.y * cos(0.1);
	ray->plane.x = ray->plane.x * cos(0.1) - ray->plane.y * sin(0.1);
	ray->plane.y = old_plane_x * sin(0.1) + ray->plane.y * cos(0.1);
}

void	rotate_left(t_ray_data *ray)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir.x;
	old_plane_x = ray->plane.x;
	ray->dir.x = ray->dir.x * cos(-0.1) - ray->dir.y * sin(-0.1);
	ray->dir.y = old_dir_x * sin(-0.1) + ray->dir.y * cos(-0.1);
	ray->plane.x = ray->plane.x * cos(-0.1) - ray->plane.y * sin(-0.1);
	ray->plane.y = old_plane_x * sin(-0.1) + ray->plane.y * cos(-0.1);
}
