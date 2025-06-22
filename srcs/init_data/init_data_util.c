/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:56:17 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/22 03:15:46 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_map_data(t_map_data *map_data)
{
	if (!map_data)
		return ;
	free(map_data->north_path);
	free(map_data->south_path);
	free(map_data->east_path);
	free(map_data->west_path);
	free(map_data->ceiling);
	free(map_data->floor);
	free_double_array(map_data->map);
	free(map_data);
}

void	exit_error_init_data(char *str,
						t_map_data *map_data,
						t_line **head)
{
	clean_map_data(map_data);
	free_line_list(head);
	exit_error(str);
}
