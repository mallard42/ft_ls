/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:34:28 by mallard           #+#    #+#             */
/*   Updated: 2016/11/18 16:17:54 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void				ft_putnbr_fd(int n, int fd)
{
	int				div;
	unsigned int	nb;

	div = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = n * -1;
	}
	else
		nb = n;
	while (nb / div >= 10)
		div = div * 10;
	while (div != 0)
	{
		ft_putchar_fd('0' + (nb / div), fd);
		nb = nb - ((nb / div) * div);
		div = div / 10;
	}
}
