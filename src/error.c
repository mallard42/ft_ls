/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:47:21 by mallard           #+#    #+#             */
/*   Updated: 2017/04/20 16:29:17 by mallard          ###   ########.fr       */
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

void	error_mod(char *str)
{
	ft_putstr("ft_ls: ");
	ft_putstr(str);
	ft_putendl(": Permission denied");
	exit(EXIT_FAILURE);
}

void	error_file(char *str)
{
	ft_putstr("ft_ls: ");
	ft_putstr(str);
	ft_putendl(": No such file or directory");
}

void	error(char *str)
{
	printf("je passe ici\n");
	//ft_putstr("ft_ls: ");
	//ft_putendl(strerror(errno));
}
