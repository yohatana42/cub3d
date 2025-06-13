/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshiko <yoshiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:09:25 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/13 19:55:38 by yoshiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	*get_line_info(t_line **head);

enum	line_type {
	is_empty,
	texture,
	color,
	map
};

void	validate_infile_format(t_line **head)
{
	t_line	*curr;
	int		line_count;
	int		*line_info;
	int		i;
	int		j;

	curr = *head;
	i = 0;
	j = 0;
	line_count = count_line_list(head);
	line_info = get_line_info(head);
	while (i < line_count)
	{
		if (line_info[i] == texture)
		{
			j = i;
			while (line_info[j] == texture)
				j++;
			if (j - i != 4)
			{
				free_line_list(head);
				exit_error("invalid map");
			}
		}
		// 要素が連続していること
		// 要素が必要以上に存在しないこと
		// mapが最後に記載されていること
		i++;
	}
}

static int	*get_line_info(t_line **head)
{
	t_line	*curr;
	int		line_count;
	int		*line_info;
	int		index;

	curr = *head;
	line_info = (int *)ft_calloc(sizeof(int), line_count);
	if (!line_info)
	{
		free_line_list(head);
		exit_error("");
	}
	while (curr)
	{
		if (is_texture(curr->str))
			line_info[index] = texture;
		if (is_color(curr->str))
			line_info[index] = color;
		if (is_map(curr->str))
			line_info[index] = map;
		if (ft_strcmp("\n", curr->str) == 0)
			line_info[index] = is_empty;
		curr = curr->next;
		index++;
	}
	return (line_info);
}
