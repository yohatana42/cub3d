/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:14:38 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 15:46:28 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_event(t_mlx_data *mlx_data, t_map_data *map_data)
{
	(void)mlx_data;
	(void)map_data;
	mlx_hook(mlx_data->win, ON_DESTROY, 0, close_window, mlx_data);
	mlx_key_hook(mlx_data->win, key_hook, mlx_data);
}
