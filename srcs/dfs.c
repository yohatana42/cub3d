/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:40:12 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/22 03:06:13 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int			dfs_exec(t_maps *maps,
						int x,
						int y);
static int			get_player_position_x(char **map);
static int			get_player_position_y(char **map);
static void			free_maps(t_maps *maps, t_line *curr);

void	dfs(t_maps *maps, t_line **head, t_line *curr)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = get_player_position_x(maps->map);
	y = get_player_position_y(maps->map);
	dfs_exec(maps, x, y);
	i = 0;
	while (i < count_line_map(curr))
	{
		j = 0;
		while (j < get_max_len(curr))
		{
			if ((i == 0 || i == count_line_map(curr) - 1 || j == 0
					|| j == get_max_len(curr) - 1)
				&& maps->search_map[i][j] == 1)
			{
				free_maps(maps, curr);
				exit_error_infile_format("map must be surrounded '1'", head);
			}
			j++;
		}
		i++;
	}
}

static void	free_maps(t_maps *maps, t_line *curr)
{
	free_double_array(maps->map);
	free_double_array_int(maps->search_map, count_line_map(curr));
}

static int	dfs_exec(t_maps *maps,
				int x,
				int y)
{
	if (x < 0 || (int)ft_strlen(maps->map[0]) - 1 < x
		|| y < 0 || count_double_array(maps->map) - 1 < y)
		return (0);
	if (maps->search_map[y][x] == 1)
		return (0);
	if (maps->map[y][x] == WALL)
		return (0);
	maps->search_map[y][x] = 1;
	dfs_exec(maps, x + 1, y);
	dfs_exec(maps, x -1, y);
	dfs_exec(maps, x, y + 1);
	dfs_exec(maps, x, y - 1);
	return (0);
}

static int	get_player_position_x(char **map)
{
	int			i;
	int			j;
	bool		break_flg;

	break_flg = false;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
			{
				break_flg = true;
				break ;
			}
			j++;
		}
		if (break_flg)
			break ;
		i++;
	}
	return (j);
}

static int	get_player_position_y(char **map)
{
	int			i;
	int			j;
	bool		break_flg;

	break_flg = false;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
			{
				break_flg = true;
				break ;
			}
			j++;
		}
		if (break_flg)
			break ;
		i++;
	}
	return (i);
}
