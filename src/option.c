/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:31:53 by mallard           #+#    #+#             */
/*   Updated: 2017/04/18 18:21:14 by mallard          ###   ########.fr       */
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

t_dir	*option_add(t_opt env, char **tab)
{
	int		i;
	t_dir	*lst;

	i = -1;
	lst = NULL;
	if (env.opt_d == 1)
	{
		if (!(lst = dirnew(".", tab)))
			return (0);
		option_sort(env, lst, 1, tab);
	}
	else
	{
		printf("1\n");
		if (env.opt_maj_r == 1)
			while (tab[++i] != NULL)
				recursive_file(tab[i], env);
		else
		{
			dir_default(tab, env, &lst);
			option_sort(env, lst, 1, tab);
		}
	}
	return (lst);
}

void	option_print(t_opt env, t_dir *lst, int size, int i)
{
	if (size != 1)
	{
		ft_putstr(lst->path);
		ft_putendl(":");
	}
	if (env.opt_l == 1)
		opt_l(lst->path, lst->file, env);
	else
		print_tab(lst->file);
	if (i != size - 1)
		ft_putstr("\n");
}

void	option_sort(t_opt env, t_dir *lst, int print, char **tab)
{
	int		size;
	int		i;

	i = 0;
	size = sizelst(&lst);
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
			option_print(env, lst, tablen(tab), i);
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
