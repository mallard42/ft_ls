/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:28:09 by mallard           #+#    #+#             */
/*   Updated: 2017/03/17 17:09:42 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void				*ft_memchr(const void *str, int c, size_t n)
{
	int				i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while ((size_t)i < n)
	{
		if (s[i] == (unsigned char)c)
			return ((void *)(s + i));
		else
			i++;
	}
	return (NULL);
}
