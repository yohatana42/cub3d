/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:37:58 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 16:35:45 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_line	*create_line_node(char str);
static bool		add_line_list(t_line *node, t_line **head);

t_line	**read_map_file(char *map_file, t_line **head)
{
	int		fd;
	char	*str;

	fd = open(map_file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		if (add_line_list(create_line_node(str), head))
		{
			free_line_list(head);
			exit_error("failed: malloc");
		}
		str = get_next_line(fd);
	}
	close(fd);
	return (head);
}

static t_line	*create_line_node(char str)
{
	t_line	*node;

	node = (t_line *)ft_calloc(sizeof(t_line), 1);
	if (!node)
		return (NULL);
	node->str = str;
	node->next = NULL;
	return (node);
}

static bool	add_line_list(t_line *node, t_line **head)
{
	t_line	*last_node;

	if (!node)
		return (true);
	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;
	if (head == NULL)
	{
		*head = node;
	}
	else
	{
		last_node->next = node;
	}
	return (false);
}
