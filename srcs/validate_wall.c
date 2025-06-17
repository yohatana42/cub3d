/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:59:59 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/17 14:22:22 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// static void	copy_map_line(char *map_line, t_line *curr);
static int	count_line_map(t_line *curr);

void	validate_wall(t_line *curr, t_line **head)
{
	char	**map;
	t_line	*line;
	int		i;
	int		max_len;

	(void)head;
	printf("curr->str %s\n", curr->str);
	line = curr;
	max_len = get_max_len(curr);
	printf("count line %d\n", count_line_map(curr));
	map = (char **)ft_calloc(sizeof(char *), count_line_map(curr));
	i = 0;
	while (count_line_map(curr) > i)
	{
		map[i] = ft_calloc(sizeof(char), max_len);
		ft_strlcpy(map[i], line->str, max_len);
		printf("i %d map[i] %s\n", i, map[i]);
		line = line->next;
		i++;
	}

	// 深さ優先探索
}

// static void	copy_map_line(char *map_line, t_line *curr)
// {
// 	int	i;

// 	i = 0;
// 	while (curr->str[i])
// 	{
// 		map_line[i] = curr->str[i];
// 		i++;
// 	}
// 	while (map_line[i])
// 	{
// 		map_line[i] = '0';
// 		i++;
// 	}
// }

static int	count_line_map(t_line *curr)
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
