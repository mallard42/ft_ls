/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:43:07 by mallard           #+#    #+#             */
/*   Updated: 2017/05/15 11:58:55 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*str;

	str = malloc(size);
	if (!str)
		return (NULL);
	ft_memset(str, '\0', size);
	return (str);
}
