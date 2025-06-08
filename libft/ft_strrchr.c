/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:53:19 by yohatana          #+#    #+#             */
/*   Updated: 2025/06/08 14:25:13 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		flg;
	char	*result;
	char	chara;

	i = 0;
	flg = 0;
	result = (char *)s;
	chara = c;
	while (s[i] != '\0')
	{
		if (s[i] == chara)
		{
			result = (char *)s + i;
			flg = 1;
		}
		i++;
	}
	if (flg > 0)
		return (result);
	else if (chara == '\0' && s[i] == '\0')
		return (result + i);
	else
		return (NULL);
}
