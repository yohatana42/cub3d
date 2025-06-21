/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:26:27 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/21 19:28:55 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	perform_dda(t_ray_data *ray, int world_map[8][8])
{
	bool	hit;

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
