/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:57:54 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/15 18:24:21 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_infile(t_line **head)
{
	validate_infile_format(head);
	validate_line_format(head);
}

int	count_line_list(t_line **head)
{
	t_line	*curr;
	int		count;

	count = 0;
	curr = *head;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
