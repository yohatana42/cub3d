/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:08:24 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/20 15:26:50 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_texture(char *line)
{
	if (ft_strncmp("NO", line, 2) == 0
		|| ft_strncmp("SO", line, 2) == 0
		|| ft_strncmp("EA", line, 2) == 0
		|| ft_strncmp("WE", line, 2) == 0)
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
