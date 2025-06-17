/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:08:24 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/17 14:21:59 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_texture(char *line)
{
	if (ft_strncmp("NO", line, 2) == 0 || \
		ft_strncmp("SO", line, 2) == 0 || \
		ft_strncmp("EA", line, 2) == 0 || \
		ft_strncmp("WE", line, 2) == 0)
	{
		return (true);
	}
	return (false);
}

bool	is_color(char *line)
{
	if (ft_strncmp("F", line, 1) == 0 || ft_strncmp("C", line, 1) == 0)
	{
		return (true);
	}
	return (false);
}

bool	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			return (true);
		i++;
	}
	return (false);
}

int	get_max_len(t_line *curr)
{
	t_line	*line;
	int		max_len;
	int		temp;

	line = curr;
	max_len = 0;
	temp = 0;
	while (line)
	{
		temp = ft_strlen(line->str);
		if (temp > max_len)
			max_len = temp;
		line = line->next;
	}
	return (max_len);
}
