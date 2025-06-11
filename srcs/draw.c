/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:34:16 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/08 15:37:39 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw(t_mlx_data *mlx_data, t_map_data *map_data)
{
	(void)map_data;
	render_next_frame(mlx_data);
	mlx_loop(mlx_data->mlx);
}
