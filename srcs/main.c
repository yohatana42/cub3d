/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:04:52 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/12 14:22:41 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map_data	map_data;
	t_mlx_data	mlx_data;

	if (argc != 2)
		exit_error("usage: ./cub3d [file name].cub");
	init_data(argv[1], &map_data);
	validate_infile(&map_data);
	init_mlx(&mlx_data);
	draw_init(&mlx_data, &map_data);
	mlx_event(&mlx_data, &map_data);
	draw(&mlx_data, &map_data);
	clean_up(&mlx_data, &map_data);
	return (EXIT_SUCCESS);
}
