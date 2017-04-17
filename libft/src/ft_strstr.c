/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:55:57 by mallard           #+#    #+#             */
/*   Updated: 2017/03/17 13:31:04 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char			*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (little[j] != '\0' && big[i] != '\0')
	{
		if (little[j] == big[i])
		{
			while (little[j] == big[i] && (little[j] != '\0' &&
					big[i] != '\0'))
			{
				i++;
				j++;
			}
			if (j == ft_strlen((char *)little))
				return ((char *)big + (i - j));
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
