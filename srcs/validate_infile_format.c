/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshiko <yoshiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:09:25 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/13 20:48:45 by yoshiko          ###   ########.fr       */
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
			i = j;
		}
		if (line_info[i] == color)
		{
			j = i;
			while (line_info[j] == color)
				j++;
			if (j - i != 2)
			{
				free_line_list(head);
				exit_error("invalid map");
			}
			i = j;
		}
		if (line_info[i] == map)
		{
			j = i;
			while (line_info[j] == map)
				j++;
			if (line_count - 1 != j)
			{
				free_line_list(head);
				exit_error("invalid map");
			}
		}
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
