/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:22:25 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/16 19:05:17 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	validate_texture(t_line *curr, t_line **head);
static void	validate_color(t_line *curr, t_line **head);

void	validate_line_format(t_line **head)
{
	t_line	*curr;
	char	**map;
/*
	・validate_textture
	空白区切りであること
	pathが存在すること

	・validate_color
	空白区切り
	数値である

	・validate_map
	壁で囲まれてること
	文字種類がただしいか
*/
	curr = *head;
	while (curr)
	{
		if (is_texture(curr->str))
		{
			validate_texture(curr, head);
		}
		curr = curr->next;
	}
}

static void	validate_texture(t_line *curr, t_line **head)
{
	char	**path;
	int		fd;

	path = ft_split(curr->str, ' ');
	if (!path)
	{
		free_line_list(head);
		exit_error("");
	}
	if (count_double_array(path) != 2)
		exit_error("");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("");
	free_double_array(path);
}

static void	validate_color(t_line *curr, t_line **head)
{
	char	**first;
	char	**second;

	first = ft_split(curr->str, ' ');
	second = ft_split(curr->next->str, ' ');
	if (!first || second)
	{
		free_line_list(head);
		exit_error("");
	}
	if (count_double_array(first) != 4 || count_double_array(second) != 4)
	{
		free_line_list(head);
		exit_error("");
	}
	while ()
	{

	}
	free_double_array(first);
	free_double_array(second);
}

// util
int	count_double_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	free_double_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
