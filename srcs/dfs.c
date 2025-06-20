/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:40:12 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/20 16:07:50 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_position	get_start(char **map);
static int			dfs_exec(t_maps *maps,
						int x, \
						int y, \
						t_position start);
static int			dfs_exec_helper(t_maps *maps,
						int x, \
						int y, \
						t_position start);

void	dfs(t_maps *maps, t_line **head, t_line *curr)
{
	t_position	start;
	t_position	now;

	printf("dfs\n");

	(void)curr;
	start = get_start(maps->map);
	now = get_start(maps->map);
	if (dfs_exec(maps, now.x, now.y, start) == 0)
	{
		exit_error_infile_format("map must allowed '1'", head);
	}
}

static int	dfs_exec(t_maps *maps,
					int x, \
					int y, \
					t_position start)
{
	int			status;

	printf("x %d y %d\n", x, y);
	if (maps->search_map[y][x] == 1)
		return (0);
	if (x == start.x && y == start.y && maps->search_map[y][x] == 1)
		return (1);
	maps->search_map[y][x] = 1;
	if (x < 0 || (int)ft_strlen(maps->map[0]) - 1 < x \
		|| y < 0 || count_double_array(maps->map) - 1 < y)
		return (0);
	if (maps->map[y][x] == SPACE)
		return (0);
	status = dfs_exec_helper(maps, x, y, start);
	if (status == 0)
		return (0);
	else
		return (1);
}

static int	dfs_exec_helper(t_maps *maps,
					int x, \
					int y, \
					t_position start)
{
	int			status_r;
	int			status_l;
	int			status_u;
	int			status_d;

	status_r = dfs_exec(maps, x + 1, y, start);
	status_l = dfs_exec(maps, x -1, y, start);
	status_u = dfs_exec(maps, x, y +1, start);
	status_d = dfs_exec(maps, x, y -1, start);
	if (status_r == 1 || status_l == 1 || status_u == 1 || status_d == 1)
		return (1);
	else
		return (0);
}

static t_position	get_start(char **map)
{
	t_position	start;
	int			i;
	int			j;
	bool		break_flg;

	i = 0;
	break_flg = false;
	while (map[i])
	{
		j = 0;
		while (map[j])
		{
			if (map[i][j] == WALL)
			{
				start.x = j;
				start.y = i;
				break_flg = true;
				break ;
			}
			j++;
		}
		if (break_flg)
			break ;
		i++;
	}
	return (start);
}
