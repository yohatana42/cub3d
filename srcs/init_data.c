/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:31:52 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/21 14:09:11 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_texture(t_line *line, t_map_data *map_data, t_line **head);
static void	set_color(t_line *line, t_map_data *map_data, t_line **head);
static char	**create_map_array(t_line *curr, \
								t_line **head, \
								t_map_data *map_data);
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
		if (is_color(line->str))
			set_color(line, map_data, head);
		if (is_map(line->str))
		{
			set_map(line, map_data, head);
			break ;
		}
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
		exit_error_infile_format("failed: malloc", head);
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
