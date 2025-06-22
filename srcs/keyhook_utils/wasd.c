/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:18:46 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/22 04:03:27 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_ray_data *ray)
{
	ray->pos.x += ray->dir.x * 0.1;
	ray->pos.y += ray->dir.y * 0.1;
}

void	move_backward(t_ray_data *ray)
{
	ray->pos.x -= ray->dir.x * 0.1;
	ray->pos.y -= ray->dir.y * 0.1;
}

void	move_left(t_ray_data *ray)
{
	ray->pos.x += ray->dir.y * 0.1;
	ray->pos.y -= ray->dir.x * 0.1;
}

void	move_right(t_ray_data *ray)
{
	ray->pos.x -= ray->dir.y * 0.1;
	ray->pos.y += ray->dir.x * 0.1;
}
