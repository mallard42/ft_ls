/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:12:02 by mallard           #+#    #+#             */
/*   Updated: 2017/05/10 11:24:55 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	rev_sort(char **file)
{
	int				i;
	int				j;
	char			*tmp;

	i = 0;
	j = tablen(file) - 1;
	while (i < tablen(file) / 2)
	{
		tmp = file[i];
		file[i] = file[j];
		file[j] = tmp;
		i++;
		j--;
	}
}

void	modification_sort(char *path, char **tab)
{
	struct stat		buf1;
	struct stat		buf2;
	int				i;
	char			*tmp;

	i = -1;
	while (tab[++i + 1] != NULL)
	{
		lstat(double_path(path, tab[i]), &buf1);
		lstat(double_path(path, tab[i + 1]), &buf2);
		if (buf1.st_mtimespec.tv_sec < buf2.st_mtimespec.tv_sec)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		if (buf1.st_mtimespec.tv_sec == buf2.st_mtimespec.tv_sec)
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
	}
}

void	creation_sort(char *path, char **tab)
{
	struct stat		buf1;
	struct stat		buf2;
	int				i;
	char			*tmp;

	i = -1;
	while (tab[++i + 1] != NULL)
	{
		lstat(double_path(path, tab[i]), &buf1);
		lstat(double_path(path, tab[i + 1]), &buf2);
		if (buf1.st_birthtimespec.tv_sec < buf2.st_birthtimespec.tv_sec)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		if (buf1.st_birthtimespec.tv_sec == buf2.st_birthtimespec.tv_sec)
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
	}
}

void	access_sort(char *path, char **tab)
{
	struct stat		buf1;
	struct stat		buf2;
	int				i;
	char			*tmp;

	i = -1;
	while (tab[++i + 1] != NULL)
	{
		lstat(double_path(path, tab[i]), &buf1);
		lstat(double_path(path, tab[i + 1]), &buf2);
		if (buf1.st_atimespec.tv_sec < buf2.st_atimespec.tv_sec)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		if (buf1.st_atimespec.tv_sec == buf2.st_atimespec.tv_sec)
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
	}
}

void	status_sort(char *path, char **tab)
{
	struct stat		buf1;
	struct stat		buf2;
	int				i;
	char			*tmp;

	i = -1;
	while (tab[++i + 1] != NULL)
	{
		lstat(double_path(path, tab[i]), &buf1);
		lstat(double_path(path, tab[i + 1]), &buf2);
		if (buf1.st_ctimespec.tv_sec < buf2.st_ctimespec.tv_sec)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		if (buf1.st_ctimespec.tv_sec == buf2.st_ctimespec.tv_sec)
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
	}
}
