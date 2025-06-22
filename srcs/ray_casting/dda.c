/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:26:27 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/22 03:03:01 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	advance_ray(t_ray_data *ray);

void	perform_dda(t_ray_data *ray, t_map_data *map_data)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		advance_ray(ray);
		if (ray->map.y < 0 || (unsigned int)ray->map.y >= map_data->height
			|| ray->map.x < 0 || (unsigned int)ray->map.x >= map_data->width
			|| map_data->map[(int)ray->map.y][(int)ray->map.x] == '1')
			hit = true;
	}
}

static void	advance_ray(t_ray_data *ray)
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
}
