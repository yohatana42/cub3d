/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:57:54 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/11 19:17:23 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_texture(char *line);
static bool	is_roof_floor(char *line);
static bool	is_map(char *line);

/*
1. ファイル名が.cub
2. 各要素が空白で区切られていること
壁のテクスチャが存在すること
テクスチャのパスが存在すること
テクスチャのフォーマットが正しいこと
3. mapが壁で囲われてること
4. mapの文字種類が0, 1, NEWSのみ
*/
void	validate_map(t_line **head)
{
	// TODO;validate_infileにするべき
	t_line	*curr;
	bool	is_empty;

	curr = *head;
	is_empty = true;
	while (curr)
	{
		if (ft_strlen(curr->str) == 1 && ft_strcmp("\n", curr->str) == 0)
		{
			printf("is empty\n");
			is_empty = true;
		}
		else
		{
			if (is_texture(curr->str))
			{
				validate_txture_format(curr);
			}
			else if (is_roof_floor(curr->str))
			{
				printf("is roof floor\n");
				// 前の行が空白だと確認したい
				// 2行連続しているか見たい
			}
			else if (is_map(curr->str))
			{
				printf("is map\n");
				// これクソデカなのでなんとかしたい
				// map情報である
				// これが最後の要素であることを見たい
				// マップだけの
			}
		}
		curr = curr->next;
	}
}

static bool	is_texture(char *line)
{
	if (ft_strncmp("NO", line, 2) == 0 || \
		ft_strncmp("SO", line, 2) == 0 || \
		ft_strncmp("EA", line, 2) == 0 || \
		ft_strncmp("WE", line, 2) == 0)
	{
		printf("%s", line);
		return (true);
	}
	return (false);
}

static bool	is_roof_floor(char *line)
{
	if (ft_strncmp("F", line, 1) == 0 || ft_strncmp("C", line, 1) == 0)
	{
		printf("%s", line);
		return (true);
	}
	return (false);
}

static bool	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			return (true);
		i++;
	}
	return (false);
}

// return 1 is error
bool	validate_txture(t_line *line)
{
	int		i;
	char	*path;

	/*
		空白で分割されていること
		パスが有効なこと
		同じ先頭２文字がないこと
		４つ連続で記載されていること
	*/
	if (line->str[2] != ' ')
		return (true);
	return (false);
}
