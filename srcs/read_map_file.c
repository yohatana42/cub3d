/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:37:58 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/11 14:25:20 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_line	*create_line_node(char *str);
static bool		add_line_list(t_line *node, t_line **head);
static char		*make_path(char *map_file);

t_line	**read_map_file(char *map_file, t_line **head)
{
	int		fd;
	char	*str;
	char	*path;

	path = make_path(map_file);
	fd = open(path, O_RDONLY);
	free(path);
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
		printf("str %s\n", str);
	}
	close(fd);
	return (head);
}

static char	*make_path(char *map_file)
{
	char	*path;
	int		len;

	len = ft_strlen(map_file);
	if (ft_strcmp(&map_file[len - 4], ".cub"))
		exit_error("usage: ./cub3d [file name].cub");
	path = ft_strjoin("maps/", map_file);
	if (!path)
		exit_error("failed: malloc");
	return (path);
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

	printf("add_line_list\n");
	if (node == NULL)
		return (true);
	// printf("head %p *head %p\n", head, *head);
	if (*head == NULL)
	{
		// printf("*head is NULL\n");
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
		temp = curr->next;
		free(curr);
	}
}
