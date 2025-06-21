/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:15:26 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/21 14:58:32 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_up(t_mlx_data *mlx_data, t_map_data *map_data)
{
	clean_map_data(map_data);
	close_window(mlx_data);
	(void)mlx_data;
}
