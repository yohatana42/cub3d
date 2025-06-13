/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:07:35 by yohatana          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/06/07 13:50:51 by yohatana         ###   ########.fr       */
=======
/*   Updated: 2025/06/08 14:25:13 by yohatana         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	if (ft_strlen(find) == 0)
		return ((char *)str);
	if (len == 0)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		count = i;
		j = 0;
		while (find[j] != '\0' && str[count] == find[j] && count < len)
		{
			j++;
			count++;
		}
		if (find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
