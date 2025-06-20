/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:31:52 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/20 21:30:56 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_texture(t_line *line, t_map_data *map_data);

void	init_data(t_line **head, t_map_data *map_data, t_mlx_data *mlx_data)
{
	t_line	*line;

	line = *head;
	while (line)
	{
		if (is_texture(line))
		{
			set_texture(line, map_data);
		}
		if (is_color(line))
		{
			set_color(line, map_data);
		}
		if (is_map(line))
		{
			set_map(line, map_data);
		}
		line = line->next;
	}
	mlx_data->map_data = map_data;
}

static void	set_texture(t_line *line, t_map_data *map_data)
{

}
