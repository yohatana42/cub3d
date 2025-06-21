/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:02:25 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/21 07:15:45 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray_direction(t_ray_data *ray)
{
	ray->ray_dir.x = ray->dir.x + ray->plane.x * ray->camera_x;
	ray->ray_dir.y = ray->dir.y + ray->plane.y * ray->camera_x;
}

void	calculate_delta_distances(t_ray_data *ray)
{
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

void	calculate_step_and_side_dist(t_ray_data *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	}
}

void	perform_dda(t_ray_data *ray, int world_map[8][8])
{
    bool    hit;

    hit = false;
    while (!hit)
    {
        if (ray->side_dist.x < ray->side_dist.y)
        {
            ray->side_dist.x += ray->delta_dist.x;
            ray->map.x += ray->step.x;
            if (ray->step.x > 0)
                ray->side = EAST;
            else
                ray->side = WEST;
        }
        else
        {
            ray->side_dist.y += ray->delta_dist.y;
            ray->map.y += ray->step.y;
            if (ray->step.y > 0)
                ray->side = SOUTH;
            else
                ray->side = NORTH;
        }
        if (ray->map.x < 0 || ray->map.x >= 8
            || ray->map.y < 0 || ray->map.y >= 8
            || world_map[(int)ray->map.x][(int)ray->map.y] > 0)
            hit = true;
    }
}

void	calculate_wall_distance(t_ray_data *ray)
{
    if (ray->side == EAST || ray->side == WEST)
        ray->wall_dist = (ray->map.x - ray->pos.x + (1 - ray->step.x) / 2) / ray->ray_dir.x;
    else
        ray->wall_dist = (ray->map.y - ray->pos.y + (1 - ray->step.y) / 2) / ray->ray_dir.y;
}
