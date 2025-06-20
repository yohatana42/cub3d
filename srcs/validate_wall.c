/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:59:59 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/20 19:36:50 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	**create_map_array(t_line *curr, t_line **head);
// static int	count_line_map(t_line *curr);
static void	copy_array(char *map, char *str, int max_len);
static void	search_player(char **map, t_line **head);

void	validate_wall(t_line *curr, t_line **head)
{
	char	**map;
	t_line	*line;

	line = curr;
	map = create_map_array(curr, head);
	search_player(map, head);
	search_wall(map, curr, head);
	free_double_array(map);
}

static char	**create_map_array(t_line *curr, t_line **head)
{
	char	**map;
	t_line	*line;
	int		i;
	int		max_len;

	line = curr;
	max_len = get_max_len(curr);
	map = (char **)ft_calloc(sizeof(char *), count_line_map(curr) + 1);
	if (!map)
		exit_error_infile_format("failed: malloc", head);
	i = 0;
	while (count_line_map(curr) > i)
	{
		map[i] = (char *)ft_calloc(sizeof(char), max_len + 1);
		if (!map[i])
		{
			free_double_array(map);
			exit_error_infile_format("failed: malloc", head);
		}
		copy_array(map[i], line->str, max_len);
		line = line->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void	copy_array(char *map, char *str, int max_len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		map[i] = str[i];
		i++;
	}
	while (max_len > i)
	{
		map[i] = '0';
		i++;
	}
	map[max_len] = '\0';
}

int	count_line_map(t_line *curr)
{
	t_line	*line;
	int		i;

	line = curr;
	i = 0;
	while (line)
	{
		if (is_map(line->str))
			i++;
		line = line->next;
	}
	return (i);
}

static void	search_player(char **map, t_line **head)
{
	int		i;
	int		j;
	bool	exist_flg;

	i = 0;
	exist_flg = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
			{
				if (exist_flg)
				{
					free_double_array(map);
					exit_error_infile_format(\
						"only 1 player is allowed in the map", head);
				}
				exist_flg = true;
			}
			j++;
		}
		i++;
	}
}
