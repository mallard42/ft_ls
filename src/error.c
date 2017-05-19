/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:47:21 by mallard           #+#    #+#             */
/*   Updated: 2017/05/16 16:36:37 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	error_option(char option)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(option);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-ARUacdlrtu] [file ...]\n");
	exit(EXIT_FAILURE);
}

void	error(char *str, t_opt env)
{
	if (errno == EACCES && env.opt_maj_r == 1)
	{
		ft_putstr(str);
		ft_putendl(":");
	}
	ft_putstr("ft_ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
}

void	single_error(char *str)
{
	ft_putstr("ft_ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
}

void	error_comp(char *str, char **tab, int *i)
{
	ft_putstr("ft_ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
	char_del(tab, *i);
	*i = *i - 1;
}
