/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:19:42 by mallard           #+#    #+#             */
/*   Updated: 2016/11/22 14:44:16 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void				ft_putnbr(int n)
{
	int				div;
	unsigned int	nb;

	div = 1;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
	}
	else
		nb = n;
	while (nb / div >= 10)
		div = div * 10;
	while (div != 0)
	{
		ft_putchar('0' + (nb / div));
		nb = nb - ((nb / div) * div);
		div = div / 10;
	}
}
