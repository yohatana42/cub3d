/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:34:16 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/21 16:28:18 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw(t_mlx_data *mlx_data)
{
	render_next_frame(mlx_data);
	mlx_loop(mlx_data->mlx);
}
