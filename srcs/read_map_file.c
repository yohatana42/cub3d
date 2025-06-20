/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:37:58 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/16 20:27:25 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_line	*create_line_node(char *str);
static bool		add_line_list(t_line *node, t_line **head);
static void		validate_infile_name(char *map_file);

t_line	**read_map_file(char *map_file, t_line **head)
{
	int		fd;
	char	*str;

	validate_infile_name(map_file);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_error("failed: open file");
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

static void	validate_infile_name(char *map_file)
{
	int		len;

	len = ft_strlen(map_file);
	if (ft_strcmp(&map_file[len - 4], ".cub"))
		exit_error("usage: ./cub3d [file name].cub");
}

static t_line	*create_line_node(char *str)
{
	t_line	*node;

	node = (t_line *)ft_calloc(sizeof(t_line), 1);
	if (!node)
		return (NULL);
	node->str = str;
	node->next = NULL;
	return (node);
}

// return true is error
static bool	add_line_list(t_line *node, t_line **head)
{
	t_line	*last_node;

	if (node == NULL)
		return (true);
	if (*head == NULL)
	{
		*head = node;
		return (false);
	}
	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = node;
	return (false);
}

void	free_line_list(t_line **head)
{
	t_line	*curr;
	t_line	*temp;

	if (head == NULL)
		return ;
	curr = *head;
	while (curr)
	{
		free(curr->str);
		curr->str = NULL;
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	head = NULL;
}
