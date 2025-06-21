/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:31:52 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/21 15:05:54 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_texture(t_line *line, t_map_data *map_data, t_line **head);
static void	set_color(t_line *line, t_map_data *map_data, t_line **head);
static void	set_map(t_line *line, \
					t_line **head, \
					t_map_data *map_data);
static void	copy_array(char *map, char *str, int max_len);

void	init_data(t_line **head, t_map_data *map_data, t_mlx_data *mlx_data)
{
	t_line	*line;

	line = *head;
	while (line)
	{
		if (is_texture(line->str))
			set_texture(line, map_data, head);
		else if (is_color(line->str))
			set_color(line, map_data, head);
		else if (is_map(line->str))
		{
			set_map(line, head, map_data);
			break ;
		}
		line = line->next;
	}
	mlx_data->map_data = map_data;
}

static void	set_texture(t_line *line, t_map_data *map_data, t_line **head)
{
	char	**path;
	char	*after_trim;

	path = ft_split(line->str, ' ');
	if (!path)
		exit_error_init_data("failed: malloc", map_data, head);
	after_trim = ft_strtrim(path[1], "\n");
	if (!after_trim)
	{
		free_double_array(path);
		exit_error_init_data("failed: malloc", map_data, head);
	}
	if (ft_strcmp("NO", path[0]) == 0)
		map_data->north_path = after_trim;
	if (ft_strcmp("SO", path[0]) == 0)
		map_data->south_path = after_trim;
	if (ft_strcmp("WE", path[0]) == 0)
		map_data->west_path = after_trim;
	if (ft_strcmp("EA", path[0]) == 0)
		map_data->east_path = after_trim;
	free_double_array(path);
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
	color = ft_calloc(sizeof(t_color), 1);
	if (!color || !colors)
	{
		free_double_array(str);
		exit_error_init_data("failed: malloc", map_data, head);
	}
	color->red = ft_atoi(colors[0]);
	color->green = ft_atoi(colors[1]);
	color->blue = ft_atoi(colors[2]);
	if (ft_strcmp(str[0], "F") == 0)
		map_data->floor = color;
	if (ft_strcmp(str[0], "C") == 0)
		map_data->ceiling = color;
	free_double_array(str);
	free_double_array(colors);
}

static void	set_map(t_line *curr, \
					t_line **head, \
					t_map_data *map_data)
{
	char	**map;
	t_line	*line;
	int		i;
	int		max_len;

	line = curr;
	max_len = get_max_len(curr);
	map = (char **)ft_calloc(sizeof(char *), count_line_map(curr) + 1);
	if (!map)
		exit_error_init_data("failed: malloc", map_data, head);
	i = 0;
	while (count_line_map(curr) > i)
	{
		map[i] = (char *)ft_calloc(sizeof(char), max_len + 1);
		if (!map[i])
		{
			free_double_array(map);
			exit_error_init_data("failed: malloc", map_data, head);
		}
		copy_array(map[i], line->str, max_len);
		line = line->next;
		i++;
	}
	map[i] = NULL;
	map_data->map = map;
}

static void	copy_array(char *map, char *str, int max_len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		map[i] = str[i];
		i++;
	}
	while (max_len > i)
	{
		map[i] = '0';
		i++;
	}
	map[max_len] = '\0';
}
