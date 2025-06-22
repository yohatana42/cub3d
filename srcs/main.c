/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:04:52 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/22 13:46:16 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx_data	mlx_data;
	t_line		*head;

	head = NULL;
	ft_memset(&mlx_data, 0, sizeof(t_mlx_data));
	if (argc != 2)
		exit_error("usage: ./cub3d [file name].cub");
	read_map_file(argv[1], &head);
	validate_infile(&head);
	init_data(&head, &mlx_data);
	free_line_list(&head);
	init_mlx(&mlx_data);
	draw_init(&mlx_data);
	mlx_event(&mlx_data);
	draw(&mlx_data);
	clean_up(&mlx_data);
	return (EXIT_SUCCESS);
}
