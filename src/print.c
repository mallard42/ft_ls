/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:47:08 by mallard           #+#    #+#             */
/*   Updated: 2017/05/15 17:56:38 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		print_multi_str(int i, int size, t_dir **lst, int file)
{
	if (file)
		size--;
	if (i <= size)
	{
		if ((*lst)->path != NULL)
		{
			ft_putstr((*lst)->path);
			ft_putendl(":");
		}
		print_tab((*lst)->file);
	}
	if (i < size)
		ft_putstr("\n");
}

void    maj_min(dev_t dev)
{
	int     i;
	int     maj;
	int     min;

	maj = major(dev);
	min = minor(dev);
	i = ft_intlen(min) - 1;
	ft_putstr("    ");
	ft_putnbr(maj);
	ft_putchar(',');
	while (++i <= 4)
		ft_putchar(' ');
	ft_putnbr(min);
}
