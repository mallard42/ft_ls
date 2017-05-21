/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:31:59 by mallard           #+#    #+#             */
/*   Updated: 2017/05/19 14:24:58 by mallard          ###   ########.fr       */
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

void	ft_default(char *str, t_opt env, int size, int rank)
{
	struct dirent	*sd;
	DIR				*dir;
	char			**tmp;
	t_dir			*new;

	tmp = NULL;
	dir = opendir(str);
	if (dir == NULL)
		error(str, env);
	else
	{
		tmp = opt_a(dir, str, env);
		closedir(dir);
		default_sort(tmp);
		if ((new = dirnew(str, tmp)))
		{
			new->rank = rank;
			print_rank(env, new, size);
		}
	}
}

void	recursive_file(char *str, t_opt env, int size, int rank)
{
	struct dirent	*sd;
	struct stat		buf;
	DIR				*dir;
	int				i;
	char			*tmp;

	i = 0;
	dir = opendir(str);
	if (dir == NULL)
		error(str, env);
	else
	{
		ft_default(str, env, size, rank);
		while ((sd = readdir(dir)) != NULL)
		{
			lstat(double_path(str, sd->d_name), &buf);
			if (S_ISDIR(buf.st_mode) && i > 1 && ft_strncmp(sd->d_name, ".", 1))
			{
				tmp = double_path(str, sd->d_name);
				recursive_file(tmp, env, size, ((rank == 0) ? rank + 1 : rank));
			}
			i++;
		}
		closedir(dir);
	}
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
