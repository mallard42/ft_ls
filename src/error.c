/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:47:21 by mallard           #+#    #+#             */
/*   Updated: 2017/06/20 15:12:30 by mallard          ###   ########.fr       */
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

char	**error(char *str)
{
	char	**tmp;

	if (!(tmp = newtab(1)))
		return (NULL);
	tmp[0] = ft_strdup("ft_ls: ");
	tmp[0] = ft_strjoin(tmp[0], str);
	tmp[0] = ft_strjoin(tmp[0], ": ");
	tmp[0] = ft_strjoin(tmp[0], strerror(errno));
	return (tmp);
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
