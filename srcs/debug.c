/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:29:57 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/11 14:27:02 by yohatana         ###   ########.fr       */
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
