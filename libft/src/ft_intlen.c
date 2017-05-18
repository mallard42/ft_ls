/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:59:19 by mallard           #+#    #+#             */
/*   Updated: 2016/12/03 18:11:25 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int			ft_intlen(int n)
{
	int				div;
	int				i;
	size_t			nbr;

	i = 1;
	div = 1;
	nbr = ft_abs(n);
	while (nbr / div >= 10)
	{
		div = div * 10;
		i++;
	}
	return (i);
}
