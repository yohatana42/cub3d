/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 03:12:35 by takitaga          #+#    #+#             */
/*   Updated: 2025/06/22 03:15:38 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	**allocate_map(t_line *curr, t_line **head, t_map_data *map_data);
static void	fill_map(char **map, t_line *curr, int max_len);
static void	copy_array(char *map, char *str, int max_len);

void	set_map(t_line *curr, t_line **head, t_map_data *map_data)
{
	char	**map;
	int		max_len;

	max_len = get_max_len(curr);
	map = allocate_map(curr, head, map_data);
	fill_map(map, curr, max_len);
	map_data->map = map;
	map_data->width = max_len;
	map_data->height = count_line_map(curr);
	find_and_set_player(map_data);
}

static char	**allocate_map(t_line *curr, t_line **head, t_map_data *map_data)
{
	char	**map;
	int		i;
	int		max_len;

	max_len = get_max_len(curr);
	map = (char **)ft_calloc(sizeof(char *), count_line_map(curr) + 1);
	if (!map)
		exit_error_init_data("failed: malloc", map_data, head);
	i = 0;
	while (count_line_map(curr) > i)
	{
		map[i] = (char *)ft_calloc(sizeof(char), max_len + 1);
		if (!map[i])
		{
			free_double_array(map);
			exit_error_init_data("failed: malloc", map_data, head);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void	fill_map(char **map, t_line *curr, int max_len)
{
	t_line	*line;
	int		i;

	line = curr;
	i = 0;
	while (count_line_map(curr) > i)
	{
		copy_array(map[i], line->str, max_len);
		line = line->next;
		i++;
	}
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
