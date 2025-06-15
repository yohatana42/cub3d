/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:09:25 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/15 16:22:56 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_line	*valid_texture_count(t_line *curr, t_line *pre, t_line **head);
static void		exit_error_infile_format(char *str, t_line **head);

void	validate_infile_format(t_line **head)
{
	t_line	*curr;
	int		line_count;
	t_line	*pre_line;

	curr = *head;
	pre_line = NULL;
	line_count = count_line_list(head);
	while (curr)
	{
		if (is_texture(curr->str))
			curr = valid_texture_count(curr, pre_line, head);
		// else	if (is_color(curr->str))
		// 	curr = valid_color_count(curr, pre_line, head);
		// else	if (is_map(curr->str))
		// 	curr = valid_map_count(curr, pre_line, head);
		pre_line = curr;
		if (ft_strcmp(curr->str, "/n") == 0)
			curr = curr->next;
		else if (!is_texture(curr->str) && !is_color(curr->str) && !is_map(curr->str))
		{
			free_line_list(head);
			exit_error("invalid map");
		}
	}
}

static t_line	*valid_texture_count(t_line *curr, t_line *pre, t_line **head)
{
	t_line	*watch_line;
	int		count;

	watch_line = curr;
	count = 0;
	if (pre != NULL && ft_strcmp(pre->str, "/n") != 0)
		exit_error_infile_format("element split empty line", head);
	while (is_texture(watch_line->str))
	{
		watch_line = watch_line->next;
		count++;
	}
	if (count != 4)
		exit_error_infile_format("texture is 4 line", head);
	curr = watch_line;
	while (watch_line)
	{
		if (is_texture(watch_line->str))
			exit_error_infile_format("too many texture line", head);
		watch_line = watch_line->next;
	}
	return (curr);
}

// static int	valid_color_count(t_line *curr, int i, t_line **head)
// {
// 	int	j;

// 	j = i;
// 	if (i != 0 && line_info[i - 1] != is_empty)
// 		exit_error_infile_format("element split empty line", head);
// 	while (line_info[j] == color)
// 		j++;
// 	if (j - i != 2)
// 		exit_error_infile_format("color is 2 line", head);
// 	i = j;
// 	while (line_info[j])
// 	{
// 		if (line_info[j] == color)
// 			exit_error_infile_format("too many color line", head);
// 		j++;
// 	}
// 	return (i);
// }


// static int	valid_map_count(t_line *curr, int line_count, t_line **head)
// {
// 	j = i;
// 	while (line_info[j] == map)
// 	j++;
// 	if (line_count - 1 != j)
// 	{
// 		exit_error_infile_format("map is last", head);
// 	}
// }

static void	exit_error_infile_format(char *str, t_line **head)
{
	free_line_list(head);
	write(2, "Error invalid map: ", 14);
	write(2, str, ft_strlen(str));
	exit(1);
}
