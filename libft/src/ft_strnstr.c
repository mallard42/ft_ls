/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:06:10 by mallard           #+#    #+#             */
/*   Updated: 2016/12/01 11:08:33 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;

	i = 0;
	if (little == big)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		if (ft_strlen((char *)little) + i > len)
			return (NULL);
		if (!ft_strcmp(ft_strsub(big, i, ft_strlen((char *)little)), little))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
