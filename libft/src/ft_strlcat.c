/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:06:56 by mallard           #+#    #+#             */
/*   Updated: 2017/04/11 11:17:41 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		total;

	total = ft_strlen(dest) + ft_strlen((char *)src);
	j = 0;
	i = 0;
	if ((size_t)ft_strlen(dest) > size)
		return (ft_strlen((char *)src) + size);
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0' && j < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (total);
}
