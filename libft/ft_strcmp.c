/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:26:50 by yohatana          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/06/07 13:38:45 by yohatana         ###   ########.fr       */
=======
/*   Updated: 2025/06/08 14:26:32 by yohatana         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;
	int	str1_len;
	int	str2_len;

	i = 0;
	if (str1 == NULL)
		str1_len = 0;
	else
		str1_len = (int)ft_strlen(str1);
	if (str2 == NULL)
		str2_len = 0;
	else
		str2_len = (int)ft_strlen(str2);
	if (str1_len != str2_len)
		return (1);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

// #include <assert.h>
// int	main(void)
// {
// 	assert(ft_strcmp("", "") == 0);
// 	assert(ft_strcmp("a", "a") == 0);
// 	assert(ft_strcmp("abc", "abc") == 0);
// 	assert(ft_strcmp("abc", "") == 1);
// 	assert(ft_strcmp("a", "b") == 1);
// 	assert(ft_strcmp("\n", " ") == 1);
// }
