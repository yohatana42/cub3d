/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:09:25 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/16 19:15:48 by yohatana         ###   ########.fr       */
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

void	validate_infile_format(t_line **head)
{
	t_line	*curr;
	t_line	*pre_line;

	curr = *head;
	pre_line = NULL;
	while (curr)
	{
		if (ft_strcmp(curr->str, "\n") == 0)
			curr = curr->next;
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
		if (!is_texture(curr->str) && \
			!is_color(curr->str) && !is_map(curr->str) && \
			ft_strcmp(curr->str, "\n") != 0)
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
		exit_error_infile_format("Separate elements with empty lines", head);
	while (is_texture(watch_line->str))
	{
		watch_line = watch_line->next;
		count++;
	}
	if (count != 4)
		exit_error_infile_format("texture must consist of 4 lines", head);
	curr = watch_line;
	while (watch_line)
	{
		if (is_texture(watch_line->str))
			exit_error_infile_format("too many texture lines", head);
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
		exit_error_infile_format("separate elements with empty lines", head);
	while (is_color(watch_line->str))
	{
		watch_line = watch_line->next;
		count++;
	}
	if (count != 2)
		exit_error_infile_format("color must consist of 4 lines", head);
	curr = watch_line;
	while (watch_line)
	{
		if (is_color(watch_line->str))
			exit_error_infile_format("too many color lines", head);
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
		exit_error_infile_format("separate elements with empty lines", head);
	while (is_map(watch_line->str))
	{
		watch_line = watch_line->next;
	}
	while (watch_line)
	{
		if (ft_strcmp(watch_line->str, "\n") != 0 && \
		ft_strcmp(watch_line->str, "") != 0)
			exit_error_infile_format("map must be the last element.", head);
		watch_line = watch_line->next;
	}
	curr = watch_line;
	return (curr);
}
