/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:57:54 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/15 16:26:20 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
1. ファイル名が.cub
2. 各要素が空白で区切られていること
壁のテクスチャが存在すること
テクスチャのパスが存在すること
テクスチャのフォーマットが正しいこと
3. mapが壁で囲われてること
4. mapの文字種類が0, 1, NEWSのみ
*/
void	validate_infile(t_line **head)
{
	validate_infile_format(head);
	// validate_line_format(head);
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
