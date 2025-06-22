/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:14:38 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/21 16:44:25 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_event(t_mlx_data *mlx_data)
{
	mlx_hook(mlx_data->win, ON_DESTROY, 0, clean_up, mlx_data);
	mlx_key_hook(mlx_data->win, key_hook, mlx_data);
}
