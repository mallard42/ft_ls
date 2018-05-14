/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:31:59 by mallard           #+#    #+#             */
/*   Updated: 2017/06/21 15:57:47 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	opt_d(t_opt env, char **tab, t_dir *lst, int size)
{
	option_sort(env, lst, 0, size);
	if (env.opt_l == 1)
		opt_l(lst->path, lst->file, env, 1);
	else
		print_tab(lst->file);
}

void	ft_default(char **tab, t_opt env, int size, int rank)
{
	char	*origin;
	t_dir	*tmp;
	char	**tmp2;
	DIR		*dir;

	tmp2 = NULL;
	if ((tmp = dirnew(".", tab, 0)))
		option_sort(env, tmp, 0, size);
	free(tmp);
	tmp = NULL;
	dir_default(tab, env, &tmp, rank);
	option_sort(env, tmp, 0, size);
	sizelst(&tmp);
	while (tmp)
	{
		print_rank(env, tmp, size);
		if ((dir = opendir(tmp->path)) != NULL)
		{
			closedir(dir);
			tmp2 = recursive_file(tmp->path, env, size, rank + 1);
			if (*tmp2)
				option_add(env, tmp2, size, rank + 1);
		}
		tmp = tmp->prev;
	}
}

int		if_dir(char *str)
{
	struct dirent	*sd;
	struct stat		buf;
	DIR				*dir;

	dir = opendir(str);
	if (dir == NULL)
		return (0);
	else
	{
		while ((sd = readdir(dir)) != NULL)
		{
			lstat(double_path(str, sd->d_name), &buf);
			if (S_ISDIR(buf.st_mode) && ft_strncmp(sd->d_name, ".", 1))
			{
				closedir(dir);
				return (1);
			}
		}
		closedir(dir);
	}
	return (0);
}

char	**recursive_file(char *str, t_opt env, int size, int rank)
{
	struct dirent	*sd;
	struct stat		buf;
	DIR				*dir;
	char			**tmp;

	dir = opendir(str);
	if (rec(str, dir) == 0)
		return (NULL);
	if (!(tmp = newtab(1)))
		return (NULL);
	tmp[0] = NULL;
	while ((sd = readdir(dir)) != NULL)
	{
		lstat(double_path(str, sd->d_name), &buf);
		if (S_ISDIR(buf.st_mode) && ft_strncmp(sd->d_name, ".", 1))
		{
			if (tmp[0] == NULL)
				tmp[0] = double_path(str, sd->d_name);
			else
				tmp = add_str_to_tab(tmp, double_path(str, sd->d_name));
		}
	}
	closedir(dir);
	return (tmp);
}

char	**opt_a(DIR *dir, char *str, t_opt env)
{
	char			**tab;
	int				i;
	struct dirent	*sd;

	if (!(tab = newtab(0)))
		return (0);
	if (env.opt_a == 1)
		while ((sd = readdir(dir)) != NULL)
			tab = add_str_to_tab(tab, sd->d_name);
	else if (env.opt_maj_a == 1)
	{
		i = 0;
		while ((sd = readdir(dir)) != NULL)
		{
			if (i > 1)
				tab = add_str_to_tab(tab, sd->d_name);
			i++;
		}
	}
	else
		while ((sd = readdir(dir)) != NULL)
			if (ft_strncmp(sd->d_name, ".", 1))
				tab = add_str_to_tab(tab, sd->d_name);
	default_sort(tab);
	return (tab);
}
