/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:21:32 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/07 14:20:15 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_cub_suffix(char *map_file);

int	valid_args(char *map_file)
{
	if (!is_cub_suffix(map_file))
	{
		print_error("useage: ./cub3d [file name].cub");
		return (1);
	}
	return (0);
}

static int	is_cub_suffix(char *map_file)
{
	size_t	len;

	len = ft_strlen(map_file);
	if (ft_strcmp(&map_file[len - 4], ".cub\0") == 0)
		return (1);
	else
		return (0);
}
