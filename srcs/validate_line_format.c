/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:13:06 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/16 20:37:11 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	validate_texture(t_line *curr, t_line **head);
static int	validate_color(t_line *curr, t_line **head);
static void	validate_map(t_line *curr, t_line **head);

void	validate_line_format(t_line **head)
{
	t_line	*curr;
	int		texture_all;
	int		color_all;
	// char	**map;
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
	texture_all = 0;
	color_all = 0;
	curr = *head;
	while (curr)
	{
		if (is_texture(curr->str))
			texture_all += validate_texture(curr, head);
		if (is_color(curr->str))
			color_all += validate_color(curr, head);
		if (is_map(curr->str))
			validate_map(curr, head);
		curr = curr->next;
	}
	if (texture_all != 1111 || color_all != 11)
		exit_error_infile_format("duplicate identifier found", head);
}

static int	validate_texture(t_line *curr, t_line **head)
{
	char	**path;
	int		res;

	res = 0;
	path = ft_split(curr->str, ' ');
	if (!path)
		exit_error_infile_format("failed: malloc", head);
	if (count_double_array(path) != 2)
	{
		free_double_array(path);
		exit_error_infile_format("separate elements with space", head);
	}
	if (ft_strcmp(path[0], "NO") == 0)
		res = 1;
	else if (ft_strcmp(path[0], "SO") == 0)
		res = 10;
	else if (ft_strcmp(path[0], "EA") == 0)
		res = 100;
	else if (ft_strcmp(path[0], "WE") == 0)
		res = 1000;
	free_double_array(path);
	return (res);
}

static int	validate_color(t_line *curr, t_line **head)
{
	char	**words;
	// char	**colors;
	int		res;

	res = 0;
	words = ft_split(curr->str, ' ');
	if (!words)
		exit_error_infile_format("failed: malloc", head);
	if (count_double_array(words) != 2)
	{
		free_double_array(words);
		exit_error_infile_format("separate elements with space", head);
	}
	if (ft_strcmp(words[0], "C") == 0)
		res = 1;
	if (ft_strcmp(words[0], "F") == 0)
		res = 10;
	// colors = ft_split(words[1], ',');
	// if (count_double_array(colors) != 3)
	// {
	// 	free_double_array(words);
	// 	free_double_array(colors);
	// 	exit_error_infile_format("color is 3", head);
	// }
	// int	i;
	// i = 0;
	// while (colors[i])
	// {
	// 	if (255 < ft_atoi(colors[i]) || ft_atoi(colors[i]) < 0)
	// 	{
	// 		free_double_array(words);
	// 		free_double_array(colors);
	// 		exit_error_infile_format("R,G,B colors in range [0,255]", head);
	// 	}
	// 	i++;
	// }
	free_double_array(words);
	// free_double_array(colors);
	return (res);
}

static void	validate_map(t_line *curr, t_line **head)
{
	(void)curr;
	(void)head;
}
