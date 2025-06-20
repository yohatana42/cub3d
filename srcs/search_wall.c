/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:09:07 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/20 17:35:09 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	**create_serch_map(t_line *curr, t_line **head, char **map);

void	search_wall(char **map, t_line *curr, t_line **head)
{
	t_maps	maps;

	maps.search_map = create_serch_map(curr, head, map);
	maps.map = map;
	dfs(&maps, head, curr);
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
	while (i < count_line_map(curr))
	{
		search_map[i] = ft_calloc(sizeof(int), get_max_len(curr));
		if (!search_map[i])
		{
			free_double_array(map);
			free_double_array_int(search_map, count_line_map(curr));
			exit_error_infile_format("failed: malloc", head);
		}
		i++;
	}
	return (search_map);
}
