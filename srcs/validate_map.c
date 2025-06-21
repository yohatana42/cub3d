/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:11:43 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/21 13:50:39 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	replace_space_trim_return(t_line *curr);
static void	validate_map_char(t_line *curr, t_line **head);

void	validate_map(t_line *curr, t_line **head)
{
	replace_space_trim_return(curr);
	validate_map_char(curr, head);
	validate_wall(curr, head);
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
				line->str[i] = SPACE;
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
			if (line->str[i] != WALL && line->str[i] != SPACE && \
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
