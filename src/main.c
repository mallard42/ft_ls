/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:43:12 by mallard           #+#    #+#             */
/*   Updated: 2017/06/20 14:35:02 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	print_file(t_opt env, t_dir **lst, char **tab)
{
	option_sort(env, *lst, 0, 0);
	if (env.opt_l == 1)
		opt_l((*lst)->path, (*lst)->file, env, 0);
	else
		print_tab((*lst)->file);
	if (*tab && env.opt_maj_r == 0)
		ft_putstr("\n");
	dirfree_end(lst);
}

void	multi_option(char **tab, t_opt env, int i)
{
	t_dir	*lst;
	char	**file;

	file = NULL;
	lst = NULL;
	if (env.opt_d == 1)
		option_add(env, tab, 0, 0);
	else
	{
		file = check_file(tab);
		i = (*file) ? i + 1 : i;
		if (*file != NULL)
			if ((lst = dirnew(NULL, file, 0)))
				print_file(env, &lst, tab);
		if (*tab != NULL)
		{
			if ((lst = dirnew(".", tab, 0)))
				option_sort(env, lst, 0, i);
			option_add(env, tab, i, i);
		}
	}
}

void	multi_str(char **tab)
{
	t_dir	*lst;
	int		i;
	int		size;
	t_opt	env;
	char	**file;

	lst = NULL;
	tab = del_str_to_tab(tab, 1);
	ini_opt(&env);
	i = check_tab(tab);
	file = check_file(tab);
	if (*file != NULL)
		print_tab(file);
	if (*tab != NULL)
	{
		if (*file != NULL)
			ft_putstr("\n");
		dir_default(tab, env, &lst, tablen(tab) - 1);
		size = sizelst(&lst);
		while (lst != NULL)
		{
			print_multi_str(++i, size, &lst, (*file) ? 1 : 0);
			lst = lst->prev;
		}
	}
}

char	*tabtostr(char **tab)
{
	int		i;
	char	*str;

	i = 1;
	str = NULL;
	str = ft_strdup("-");
	while (tab[i] && tab[i][0] == '-' && ft_strcmp(tab[i], "--"))
	{
		str = ft_strjoin_f(str, &(tab[i][1]), 0);
		i++;
	}
	return (str);
}

int		main(int ac, char **av)
{
	t_opt	env;
	int		i;

	if (ac >= 2 && av[1][0] == '-')
	{
		check_option(tabtostr(av), "ARUacdlrtu");
		env = rec_option(tabtostr(av));
		av = del_str_to_tab(av, 1);
		i = check_tab(av);
		multi_option(av, env, i);
	}
	else
		multi_str(av);
	return (0);
}
