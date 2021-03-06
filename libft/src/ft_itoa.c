/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:27:59 by mallard           #+#    #+#             */
/*   Updated: 2017/05/16 16:43:45 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char			*alloc(long n)
{
	int				div;
	char			*str;
	unsigned int	nb;

	str = NULL;
	nb = ft_intlen(n);
	div = 1;
	if (n < 0)
		nb++;
	if (!(str = ft_strnew(ft_intlen(nb))))
		return (0);
	return (str);
}

static char			*instr(int div, size_t nbr, int n)
{
	long			i;
	char			*str;

	if (!(str = alloc(nbr)))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	i = 0;
	if (str[i] == '-')
		i = 1;
	while (nbr / div >= 10)
		div = div * 10;
	while (div != 0)
	{
		str[i] = '0' + (nbr / div);
		nbr = nbr - ((nbr / div) * div);
		div = div / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char				*ft_itoa(int n)
{
	int				div;
	size_t			nb;
	char			*str;

	str = NULL;
	div = 1;
	nb = ft_abs(n);
	str = instr(div, nb, n);
	return (str);
}
