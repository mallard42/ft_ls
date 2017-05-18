/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:48:22 by mallard           #+#    #+#             */
/*   Updated: 2016/12/03 18:11:16 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t			ft_abs(int nb)
{
	size_t		i;

	i = nb;
	if (nb < 0)
		return (i * -1);
	return (i);
}
