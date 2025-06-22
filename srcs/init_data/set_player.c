/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 03:08:20 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/22 03:15:51 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_direction(t_map_data *map_data, char player_char);

void	find_and_set_player(t_map_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)map_data->height)
	{
		j = 0;
		while (j < (int)map_data->width && map_data->map[i][j])
		{
			if (is_player(map_data->map[i][j]))
			{
				map_data->player_pos.x = j + 0.5;
				map_data->player_pos.y = i + 0.5;
				set_player_direction(map_data, map_data->map[i][j]);
				map_data->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	set_player_direction(t_map_data *map_data, char player_char)
{
	if (player_char == 'N')
		map_data->player_dir = NORTH;
	else if (player_char == 'S')
		map_data->player_dir = SOUTH;
	else if (player_char == 'W')
		map_data->player_dir = WEST;
	else if (player_char == 'E')
		map_data->player_dir = EAST;
}
