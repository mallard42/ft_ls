/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:43:12 by mallard           #+#    #+#             */
/*   Updated: 2017/04/21 20:06:17 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	multi_option(char **tab)
{
	t_opt	env;
	t_dir	*lst;
	char	**file;

	lst = NULL;
	check_option(tabtostr(tab), "ARUacdlrtu");
	env = rec_option(tabtostr(tab));
	tab = del_str_to_tab(tab, 1);
	file = check_file(tab);
	if (file != NULL)
	{
		if ((lst = dirnew(".", file)))
		{
			option_sort(env, lst, 0, tab);
			print_tab(lst->file);
			dirfree_end(&lst);
		}
	}
	if (tab)
		if (env.opt_d == 0)
			if ((lst = dirnew(".", tab)))
				option_sort(env, lst, 0, tab);
	option_add(env, tab);
}

void	multi_str(char **tab)
{
	t_dir	*lst;
	int		i;
	int		size;
	t_opt	env;

	i = 0;
	lst = NULL;
	tab = del_str_to_tab(tab, 1);
	ini_opt(&env);
	dir_default(tab, env, &lst);
	size = sizelst(&lst);
	while (lst != NULL)
	{
		option_print(env, lst, size, i);
		i++;
		lst = lst->prev;
	}
}

char	*tabtostr(char **tab)
{
	int		i;
	char	*str;

	i = 1;
	str = NULL;
	str = ft_strdup("-");
	while (tab[i] && tab[i][0] == '-')
	{
		str = ft_strjoin_f(str, &(tab[i][1]), 0);
		i++;
	}
	return (str);
}

int		main(int ac, char **av)
{
	if (ac >= 2 && av[1][0] == '-' && ft_strcmp(av[1], "--"))
		multi_option(av);
	else
		multi_str(av);
	return (0);
}
