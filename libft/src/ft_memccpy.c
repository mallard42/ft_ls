/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:56:02 by mallard           #+#    #+#             */
/*   Updated: 2017/04/11 17:41:00 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*str;
	char		*temp;

	str = (char *)dest;
	temp = (char *)src;
	i = 0;
	while (i < n)
	{
		str[i] = temp[i];
		if (str[i] == c)
			return (dest + (i + 1));
		i++;
	}
	return (NULL);
}
