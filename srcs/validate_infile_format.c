/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshiko <yoshiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:09:25 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/13 22:24:16 by yoshiko          ###   ########.fr       */
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

	curr = *head;
	i = 0;
	j = 0;
	line_count = count_line_list(head);
	line_info = get_line_info(head);
	while (i < line_count)
	{
		if (line_info[i] == texture)
		{
			i = valid_texture_count();
		}
		if (line_info[i] == color)
		{
			i = valid_color_count();
		}
		if (line_info[i] == map)
		{
			i = valid_map_count();
		}
		i++;
	}
}

static int	valid_texture_count(t_line *curr, int i, t_line **head)
{
	int	j;

	j = i;
	if (i != 0 && line_info[i - 1] != is_empty)
		exit_error_infile_format("element split empty line", head);
	while (line_info[j] == texture)
		j++;
	if (j - i != 4)
		exit_error_infile_format("texture is 4 line", head);
	i = j;
	while (line_info[j])
	{
		if (line_info[j] == texture)
			exit_error_infile_format("too many texture line", head);
		j++;
	}
	return (i);
}

static int	valid_color_count(t_line *curr, int i, t_line **head)
{
	int	j;

	j = i;
	if (i != 0 && line_info[i - 1] != is_empty)
		exit_error_infile_format("element split empty line", head);
	while (line_info[j] == color)
		j++;
	if (j - i != 2)
		exit_error_infile_format("color is 2 line", head);
	i = j;
	while (line_info[j])
	{
		if (line_info[j] == color)
			exit_error_infile_format("too many color line", head);
		j++;
	}
	return (i);
}

static void	exit_error_infile_format(char *str, t_line **head)
{
	free_line_list(head);
	write(2, "Error invalid map: ", 14);
	write(2, str, ft_strlen(str));
	exit(1);
}

static int	valid_map_count(t_line *curr, int line_count, t_line **head)
{
	j = i;
	while (line_info[j] == map)
		j++;
	if (line_count - 1 != j)
	{
		exit_error_infile_format("map is last", head);
	}
}

// コレいらない気がする
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
