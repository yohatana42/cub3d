/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:29:57 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/21 14:26:48 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_line_list(t_line **head)
{
	t_line	*temp;

	temp = *head;
	while (temp)
	{
		printf("line: %s", temp->str);
		temp = temp->next;
	}
}

void	print_init_data(t_map_data *map_data, t_mlx_data *mlx_data)
{
	int	i;

	i = 0;
	printf("%p %p\n", mlx_data->map_data, map_data);
	while (map_data->map[i])
	{
		printf("map: i %d %s\n", i, map_data->map[i]);
		i++;
	}
	printf("north_path %s\n", map_data->north_path);
	printf("south_path %s\n", map_data->south_path);
	printf("east_path %s\n", map_data->east_path);
	printf("west_path %s\n", map_data->west_path);
	printf("floor red %d\n", map_data->floor->red);
	printf("floor green %d\n", map_data->floor->green);
	printf("floor blue %d\n", map_data->floor->blue);
	printf("ceiling red %d\n", map_data->ceiling->red);
	printf("ceiling green %d\n", map_data->ceiling->green);
	printf("ceiling blue %d\n", map_data->ceiling->blue);
}
