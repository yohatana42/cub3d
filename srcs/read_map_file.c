/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:37:58 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 15:52:26 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_line	**read_map_file(char *map_file)
{
	int		fd;
	char	*str;
	t_line	*head;

	str = get_next_line(fd);
	return (&head);
}

static t_line	*create_line_node(char str)
{

}

static bool	add_line_list(t_line *node, t_line **head)
{
	return (false);
}
