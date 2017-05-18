/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:40:47 by mallard           #+#    #+#             */
/*   Updated: 2016/11/28 12:41:06 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*p_dest;
	char		*p_src;

	p_dest = (char *)dest;
	p_src = (char *)src;
	i = 0;
	if (src < dest)
	{
		while (n != 0)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	}
	if (src > dest)
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}
