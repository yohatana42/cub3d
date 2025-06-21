/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:31:52 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/20 22:06:31 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_texture(t_line *line, t_map_data *map_data, t_line **head);
static void	set_color(t_line *line, t_map_data *map_data, t_line **head);

void	init_data(t_line **head, t_map_data *map_data, t_mlx_data *mlx_data)
{
	t_line	*line;

	line = *head;
	while (line)
	{
		if (is_texture(line))
			set_texture(line, map_data, head);
		if (is_color(line))
			set_color(line, map_data, head);
		if (is_map(line))
			set_map(line, map_data, head);
		line = line->next;
	}
	mlx_data->map_data = map_data;
}

static void	set_texture(t_line *line, t_map_data *map_data, t_line **head)
{
	char	**path;

	path = ft_split(line->str, ' ');
	if (!path)
		exit_error_init_data("failed: malloc", map_data, head);
	if (ft_strncmp("NO", path[0], 2) == 0)
		map_data->north_path = path[1];
	if (ft_strncmp("SO", path[0], 2) == 0)
		map_data->south_path = path[1];
	if (ft_strncmp("WE", path[0], 2) == 0)
		map_data->west_path = path[1];
	if (ft_strncmp("EA", path[0], 2) == 0)
		map_data->east_path = path[1];
	free(path[0]);
}

static void	set_color(t_line *line, t_map_data *map_data, t_line **head)
{
	char	**str;
	char	**colors;
	t_color	*color;

	str = ft_split(line->str, ' ');
	if (!str)
		exit_error_init_data("failed: malloc", map_data, head);
	colors = ft_split(str[1], ',');
	if (!colors)
		exit_error_init_data("failed: malloc", map_data, head);
	color = ft_calloc(sizeof(t_color), 1);
	if (!color)
		exit_error_init_data("failed: malloc", map_data, head);
	color->red = ft_atoi(colors[0]);
	color->green = ft_atoi(colors[1]);
	color->blue = ft_atoi(colors[2]);
	if (ft_strcmp(str[0], "F"))
		map_data->floor = color;
	else
		map_data->ceiling = color;
	free_double_array(str);
	free_double_array(colors);
}

void	set_map(t_line *line, t_map_data *map_data, t_line **head)
{
	char	**map;

}

void	clean_map_data(t_map_data *map_data)
{
	free(map_data->north_path);
	free(map_data->south_path);
	free(map_data->east_path);
	free(map_data->west_path);
	free(map_data->ceiling);
	free(map_data->floor);
}

void	exit_error_init_data(char *str, t_map_data *map_data, t_line **head)
{
	clean_map_data(map_data);
	free_line_list(head);
	exit_error(str);
}
