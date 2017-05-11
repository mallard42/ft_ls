/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:31:59 by mallard           #+#    #+#             */
/*   Updated: 2017/05/11 11:02:31 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	opt_d(t_opt env, char **tab, t_dir *lst)
{
	option_sort(env, lst, 0, tab);
	if (env.opt_l == 1)
		opt_l(lst->path, lst->file, env, 1);
	else
		print_tab(lst->file);
}

void	ft_default(char *str, t_opt env)
{
	struct dirent	*sd;
	DIR				*dir;
	char			**tmp;
	t_dir			*new;

	tmp = NULL;
	dir = opendir(str);
	if (dir == NULL)
		error(str);
	else
	{
		tmp = opt_a(dir, str, env);
		closedir(dir);
		default_sort(tmp);
		if ((new = dirnew(str, tmp)))
			option_sort(env, new, 1, tmp);
	}
}

void	recursive_file(char *str, t_opt env)
{
	struct dirent	*sd;
	DIR				*dir;
	int				i;
	char			*tmp;

	i = 0;
	dir = opendir(str);
	if (dir == NULL)
		error(str);
	else
	{
		ft_default(str, env);
		while ((sd = readdir(dir)) != NULL)
		{
			if (sd->d_type == 4 && i > 1 && ft_strncmp(sd->d_name, ".", 1))
			{
				tmp = double_path(str, sd->d_name);
				recursive_file(tmp, env);
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
