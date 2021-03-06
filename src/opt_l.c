/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:00:46 by mallard           #+#    #+#             */
/*   Updated: 2017/05/16 15:03:50 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	type_file(char *str, struct stat buf)
{
	if (S_ISREG(buf.st_mode))
		ft_putstr("-");
	else if (S_ISLNK(buf.st_mode))
		ft_putstr("l");
	else if (S_ISDIR(buf.st_mode))
		ft_putstr("d");
	else if (S_ISSOCK(buf.st_mode))
		ft_putstr("s");
	else if (S_ISFIFO(buf.st_mode))
		ft_putstr("p");
	else if (S_ISCHR(buf.st_mode))
		ft_putstr("c");
	else if (S_ISBLK(buf.st_mode))
		ft_putstr("b");
	else
		ft_putstr("?");
	if (buf.st_mode & S_ISUID)
		ft_putstr("--S");
	else
	{
		ft_putstr((buf.st_mode & S_IRUSR) ? "r" : "-");
		ft_putstr((buf.st_mode & S_IWUSR) ? "w" : "-");
		ft_putstr((buf.st_mode & S_IXUSR) ? "x" : "-");
	}
}

void	mode_file(char *str, struct stat buf)
{
	type_file(str, buf);
	if (buf.st_mode & S_ISGID)
		ft_putstr("--S");
	else
	{
		ft_putstr((buf.st_mode & S_IRGRP) ? "r" : "-");
		ft_putstr((buf.st_mode & S_IWGRP) ? "w" : "-");
		ft_putstr((buf.st_mode & S_IXGRP) ? "x" : "-");
	}
	if (buf.st_mode & S_ISVTX)
		ft_putstr("--T");
	else
	{
		ft_putstr((buf.st_mode & S_IROTH) ? "r" : "-");
		ft_putstr((buf.st_mode & S_IWOTH) ? "w" : "-");
		ft_putstr((buf.st_mode & S_IXOTH) ? "x" : "-");
	}
	ft_putstr("  ");
}

void	l_total(char *str, char **tab)
{
	int				i;
	int				total;
	struct stat		buf;

	i = 0;
	total = 0;
	while (tab[i] != NULL)
	{
		lstat(double_path(str, tab[i]), &buf);
		total = total + buf.st_blocks;
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}
