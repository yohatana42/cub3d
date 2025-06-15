/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:04:52 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/15 16:06:18 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map_data	map_data;
	t_mlx_data	mlx_data;
	t_line		*head;

	head = NULL;
	ft_memset(&map_data, 0, 8);
	ft_memset(&mlx_data, 0, 8);
	if (argc != 2)
		exit_error("usage: ./cub3d [file name].cub");
	read_map_file(argv[1], &head);
	validate_infile(&head);
	init_data(&head, &map_data);
	free_line_list(&head);
	init_mlx(&mlx_data);
	draw_init(&mlx_data, &map_data);
	mlx_event(&mlx_data, &map_data);
	draw(&mlx_data, &map_data);
	free_line_list(&head);
	clean_up(&mlx_data, &map_data);
	return (EXIT_SUCCESS);
}
