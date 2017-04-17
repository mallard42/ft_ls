/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:47:21 by mallard           #+#    #+#             */
/*   Updated: 2017/04/14 11:03:50 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	error_option(char option)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(option);
	ft_putchar('\n');
	ft_putstr("usage: ls [-ARUacdlrtu] [file ...]\n");
	exit(EXIT_FAILURE);
}

void	error_mod(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putendl(": Permission denied");
	exit(EXIT_FAILURE);
}

void	error_file(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putendl(": No such file or directory");
}
