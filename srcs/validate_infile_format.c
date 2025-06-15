/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:09:25 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/15 16:58:24 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_line	*validate_texture_block(t_line *curr, \
										t_line *pre, \
										t_line **head);
static t_line	*validate_color_block(t_line *curr, \
										t_line *pre, \
										t_line **head);
static t_line	*validate_map_block(t_line *curr, \
										t_line *pre, \
										t_line **head);
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
			curr = validate_texture_block(curr, pre_line, head);
		else if (is_color(curr->str))
			curr = validate_color_block(curr, pre_line, head);
		else if (is_map(curr->str))
		{
			curr = validate_map_block(curr, pre_line, head);
			if (curr == NULL)
				return ;
		}
		pre_line = curr;
		if (ft_strcmp(curr->str, "\n") == 0)
		{
			pre_line = curr;
			curr = curr->next;
		}
		else if (!is_texture(curr->str) && \
				!is_color(curr->str) && !is_map(curr->str))
			exit_error_infile_format("", head);
	}
}

static t_line	*validate_texture_block(t_line *curr, \
										t_line *pre, \
										t_line **head)
{
	t_line	*watch_line;
	int		count;

	watch_line = curr;
	count = 0;
	if (pre != NULL && ft_strcmp(pre->str, "\n") != 0)
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

static t_line	*validate_color_block(t_line *curr, \
										t_line *pre, \
										t_line **head)
{
	t_line	*watch_line;
	int		count;

	watch_line = curr;
	count = 0;
	if (pre != NULL && ft_strcmp(pre->str, "\n") != 0)
		exit_error_infile_format("element split empty line", head);
	while (is_color(watch_line->str))
	{
		watch_line = watch_line->next;
		count++;
	}
	if (count != 2)
		exit_error_infile_format("color is 2 line", head);
	curr = watch_line;
	while (watch_line)
	{
		if (is_color(watch_line->str))
			exit_error_infile_format("too many texture line", head);
		watch_line = watch_line->next;
	}
	return (curr);
}

static t_line	*validate_map_block(t_line *curr, \
										t_line *pre, \
										t_line **head)
{
	t_line	*watch_line;

	watch_line = curr;
	if (pre != NULL && ft_strcmp(pre->str, "\n") != 0)
		exit_error_infile_format("element split empty line", head);
	while (is_map(watch_line->str))
	{
		watch_line = watch_line->next;
	}
	while (watch_line)
	{
		if (ft_strcmp(watch_line->str, "\n") != 0 && \
		ft_strcmp(watch_line->str, "") != 0)
			exit_error_infile_format("map is last element", head);
		watch_line = watch_line->next;
	}
	curr = watch_line;
	return (curr);
}

static void	exit_error_infile_format(char *str, t_line **head)
{
	free_line_list(head);
	write(2, "Error\ninvalid map: ", 20);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}
