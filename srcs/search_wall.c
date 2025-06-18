/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:09:07 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/18 19:29:58 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	**create_serch_map(t_line *curr, t_line **head, char **map);

void	search_wall(char **map, t_line *curr, t_line **head)
{
	int	**search_map;

	search_map = create_serch_map(curr, head, map);
	dfs(search_map, map, head, curr);
}

static int	**create_serch_map(t_line *curr, t_line **head, char **map)
{
	int	**search_map;
	int	i;

	search_map = (int **)ft_calloc(sizeof(int *), count_line_map(curr));
	if (!search_map)
	{
		free_double_array(map);
		exit_error_infile_format("failed: malloc", head);
	}
	i = 0;
	while (i)
	{
		search_map[i] = ft_calloc(sizeof(int), get_max_len(curr));
		if (!search_map[i])
		{
			free_double_array(map);
			free_double_array_int(search_map);
			exit_error_infile_format("failed: malloc", head);
		}
		i++;
	}
	return (search_map);
}

// static void	dfs(int **search_map, char **map, t_line **head, t_line *curr)
// {
// 	t_position	start;
// 	t_position	now;

// 	start = get_start();
// 	if (dfs_exec() == 0)
// 	{
// 		exit_error_infile_format("", head);
// 	}
// }

// int	dfs_exec(int **search_map, char **map, t_position now, t_position start)
// {
// 	int	status;

// 	if (now.x < 0 || ft_strlen(map[0]) < now.x || now.y < 0 || count_double_array(map) < now.y)
// 		return (0);
// 	search_map[now.y][now.x] = 1;
// 	status = dfs_exec(search_map, map, x + 1, y);
// 	/*
// 		左上の壁からスタートする
// 		隣が壁であるなら
// 			右に進める
// 			下に進める
// 			左に進める
// 			↑に進める
// 		隣がすべて探索済み＆壁が存在しない
// 		→不正なマップ
// 		進んだ先がスタート地点である
// 		→終了する
// 	*/
// }
