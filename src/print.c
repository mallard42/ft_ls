/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:47:08 by mallard           #+#    #+#             */
/*   Updated: 2017/05/18 18:20:07 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		print_multi_str(int i, int size, t_dir **lst, int file)
{
	if (file)
		size--;
	if (i <= size)
	{
		if ((*lst)->path != NULL)
		{
			ft_putstr((*lst)->path);
			ft_putendl(":");
		}
		print_tab((*lst)->file);
	}
	if (i < size)
		ft_putstr("\n");
}

void		maj_min(dev_t dev)
{
	int		maj;
	int		min;

	maj = major(dev);
	min = minor(dev);
	ft_putstr("   ");
	print_space(ft_itoa(maj), 4, 1);
	ft_putchar(',');
	print_space(ft_itoa(min), 4, 1);
}

char		*path_sup(char *str)
{
	int		i;

	if (str == NULL)
		return (NULL);
	i = ft_strlen(str) - 1;
	while (str[i] != '/')
		i--;
	return (ft_strsub(str, 0, i));
}

void		print_rank(t_opt env, t_dir *lst, int size)
{
	int		i;

	i = 0;
	option_sort(env, lst, 0);
	sizelst(&lst);
	while (lst != NULL)
	{
		if (lst->rank > 0)
		{
			ft_putstr(lst->path);
			ft_putendl(":");
		}
		if (env.opt_l == 1)
			opt_l(lst->path, lst->file, env, 1);
		else
			print_tab(lst->file);
		if (size > 0 && is_end(path_sup(lst->path), lst->path) == 0)
			ft_putstr("\n");
		lst = lst->prev;
	}
}
