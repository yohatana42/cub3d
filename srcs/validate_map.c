/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:11:43 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/17 12:55:36 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_max_len(t_line *curr);
static void	replace_space_trim_return(t_line *curr);
static void	validate_map_char(t_line *curr, t_line **head);

/*
・文字数が一番多いところに合わせて領域を確保
・文字の種類が01方向の三種類か
・スペースは0に置き換える
・マップを二重配列にする
・プレイヤーのいる部分が壁に囲まれているか
→プレイヤーのいる空白部分を深さ優先で塗りつぶし、すべて探索し終わった際に
一番端っこのインデックス行にはみ出していなければ良い
*/
void	validate_map(t_line *curr, t_line **head)
{
	int	max_len;

	max_len = get_max_len(curr);
	replace_space_trim_return(curr);
	validate_map_char(curr, head);
	// validate_wall(curr, head);
}

static int	get_max_len(t_line *curr)
{
	t_line	*line;
	int		max_len;
	int		temp;

	line = curr;
	max_len = 0;
	temp = 0;
	while (line)
	{
		temp = ft_strlen(curr->str);
		if (temp > max_len)
			max_len = temp;
		line = line->next;
	}
	return (max_len);
}

static void	replace_space_trim_return(t_line *curr)
{
	t_line	*line;
	int		i;

	line = curr;
	while (line)
	{
		i = 0;
		while (line->str[i])
		{
			if (line->str[i] == ' ')
				line->str[i] = '0';
			if (line->str[i] == '\n')
				line->str[i] = '\0';
			i++;
		}
		line = line->next;
	}
}

static void	validate_map_char(t_line *curr, t_line **head)
{
	t_line	*line;
	int		i;

	line = curr;
	while (line)
	{
		i = 0;
		while (line->str[i])
		{
			if (line->str[i] != '1' && line->str[i] != '0' && \
			line->str[i] != 'N' && line->str[i] != 'S' && \
			line->str[i] != 'W' && line->str[i] != 'E')
			{
				exit_error_infile_format(\
					"map characters must be 1, 0, or direction", head);
			}
			i++;
		}
		line = line->next;
	}
}
