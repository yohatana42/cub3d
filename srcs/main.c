/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:04:52 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/07 13:22:56 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error("useage: ./cub3d [file name]");
		return (1);
	}
	valid_args(argv[1]);
	return (0);
}
