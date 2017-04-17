/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:53:38 by mallard           #+#    #+#             */
/*   Updated: 2016/11/17 14:24:00 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	return (dest);
}
