/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:40:12 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/18 19:48:36 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_position	get_start(char **map);
static int			dfs_exec(int **search_map, \
					char **map, \
					t_position now, \
					t_position start);

void	dfs(int **search_map, char **map, t_line **head, t_line *curr)
{
	t_position	start;
	t_position	now;

	(void)curr;
	printf("dfs\n");
	start = get_start(map);
	now = get_start(map);
	if (dfs_exec(search_map, map, now, start) == 0)
	{
		exit_error_infile_format("map must allowed '1'", head);
	}
}

static int	dfs_exec(int **search_map, \
					char **map, \
					t_position now, \
					t_position start)
{
	t_position	right;
	t_position	left;
	t_position	up;
	t_position	down;
	int			status_r;
	int			status_l;
	int			status_u;
	int			status_d;

	printf("dfs_exec\n");
	printf("now.x %d now.y %d\n", now.x, now.y);
	printf("start.x %d start.y %d\n", start.x, start.y);

	if (now.x < 0 || (int)ft_strlen(map[0]) < now.x \
	|| now.y < 0 || count_double_array(map) < now.y)
		return (0);
	if (search_map[now.y][now.x] == 1 && (now.x != start.x && now.y != start.y))
		return (0);
	if (now.x == start.x && now.y == start.y && search_map[now.y][now.x] == 1)
		return (1);
	right.x = now.x + 1;
	right.y = now.y;
	left.x = now.x - 1;
	left.y = now.y;
	up.x = now.x;
	up.y = now.y + 1;
	down.x = now.x;
	down.y = now.y - 1;
	search_map[now.y][now.x] = 1;
	status_r = dfs_exec(search_map, map, right, start);
	status_l = dfs_exec(search_map, map, left, start);
	status_u = dfs_exec(search_map, map, up, start);
	status_d = dfs_exec(search_map, map, down, start);
	if (status_r == 0 && status_l == 0 && status_u == 0 && status_d == 0)
		return (0);
	else
		return (1);
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
				printf("i %d j %d\n", i, j);
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
