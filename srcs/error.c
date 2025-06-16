/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:21:28 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/11 19:22:42 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
}

void	exit_error(char *str)
{
	print_error(str);
	exit(EXIT_FAILURE);
}
