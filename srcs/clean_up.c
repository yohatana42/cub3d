/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:15:26 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 15:32:56 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_up(t_mlx_data *mlx_data, t_map_data *map_data)
{
	close_window(mlx_data);
	(void)mlx_data;
	(void)map_data;
}
