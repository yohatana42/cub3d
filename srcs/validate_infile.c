/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:57:54 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/17 12:34:25 by yohatana         ###   ########.fr       */
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

void	exit_error_infile_format(char *str, t_line **head)
{
	free_line_list(head);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("invalid map: ", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

int	count_double_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	free_double_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
