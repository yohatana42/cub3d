/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:09:07 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/18 15:10:39 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	search_wall(char **map, t_line *curr, t_line **head)
{
	int	**search_map;

	create_serch_map(search_map, curr, head);
	dfs();
}
