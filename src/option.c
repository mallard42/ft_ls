/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:31:53 by mallard           #+#    #+#             */
/*   Updated: 2017/06/20 14:45:43 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_opt	rec_option(char *str)
{
	t_opt	env;

	env.opt_maj_a = (ft_strstr(str, "A")) ? 1 : 0;
	env.opt_maj_r = (ft_strstr(str, "R")) ? 1 : 0;
	env.opt_maj_u = (ft_strstr(str, "U")) ? 1 : 0;
	env.opt_a = (ft_strstr(str, "a")) ? 1 : 0;
	env.opt_d = (ft_strstr(str, "d")) ? 1 : 0;
	env.opt_t = (ft_strstr(str, "t")) ? 1 : 0;
	env.opt_r = (ft_strstr(str, "r")) ? 1 : 0;
	env.opt_l = (ft_strstr(str, "l")) ? 1 : 0;
	env.opt_c = (ft_strstr(str, "c")) ? 1 : 0;
	env.opt_u = (ft_strstr(str, "u")) ? 1 : 0;
	return (env);
}

void	option_add(t_opt env, char **tab, int size, int rank)
{
	int		i;
	t_dir	*lst;

	i = -1;
	lst = NULL;
	if (env.opt_d == 1)
	{
		if ((lst = dirnew(".", tab, 0)))
			opt_d(env, tab, lst, size);
	}
	else
	{
		if (env.opt_maj_r == 1)
			ft_default(tab, env, size, rank);
		else
		{
			dir_default(tab, env, &lst, tablen(tab));
			option_sort(env, lst, 1, size);
		}
	}
}

void	option_print(t_opt env, t_dir *lst, int size, int i)
{
	if (size > 1)
	{
		if (lst->path != NULL && lst->rank > 0)
		{
			ft_putstr(lst->path);
			ft_putendl(":");
		}
	}
	if (env.opt_l == 1)
		opt_l(lst->path, lst->file, env, 1);
	else
		print_tab(lst->file);
	if (lst->prev != NULL)
		ft_putstr("\n");
}

void	option_sort(t_opt env, t_dir *lst, int print, int size)
{
	int		s;
	int		i;

	i = 0;
	s = sizelst(&lst) + size;
	while (lst != NULL)
	{
		if (env.opt_t == 1)
		{
			modification_sort(lst->path, lst->file);
			if (env.opt_u == 1)
				access_sort(lst->path, lst->file);
			if (env.opt_maj_u == 1)
				creation_sort(lst->path, lst->file);
			if (env.opt_c == 1)
				status_sort(lst->path, lst->file);
		}
		if (env.opt_r == 1)
			rev_sort(lst->file);
		if (print == 1)
			option_print(env, lst, s, i);
		lst = lst->prev;
		i++;
	}
}

void	ini_opt(t_opt *env)
{
	env->opt_maj_a = 0;
	env->opt_maj_r = 0;
	env->opt_maj_u = 0;
	env->opt_a = 0;
	env->opt_c = 0;
	env->opt_d = 0;
	env->opt_t = 0;
	env->opt_r = 0;
	env->opt_u = 0;
	env->opt_l = 0;
}
