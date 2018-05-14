/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:47:21 by mallard           #+#    #+#             */
/*   Updated: 2017/06/21 15:59:53 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		rec(char *str, DIR *dir)
{
	if (dir == NULL)
	{
		error(str);
		return (0);
	}
	return (1);
}

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
	errno = 0;
	return (tmp);
}

void	single_error(char *str)
{
	if (ft_strncmp(str, "ft_ls: ", 7))
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putstr(": ");
		ft_putendl(strerror(errno));
		errno = 0;
	}
	else
		ft_putendl(str);
}

void	error_comp(char *str, char **tab, int *i)
{
	ft_putstr("ft_ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
	char_del(tab, *i);
	*i = *i - 1;
	errno = 0;
}
