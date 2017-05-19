/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:47:08 by mallard           #+#    #+#             */
/*   Updated: 2017/05/19 14:22:37 by mallard          ###   ########.fr       */
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
	while (str[i] && str[i] != '/')
		i--;
	if (!ft_strrchr(str, '/'))
		return (str);
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
		// printf("lst->path = %s\n", lst->path);
		// printf("lst->last_path = %s\n", lst->last_path);
		// printf("ft_strcmp(lst->path, lst->last_path) = %d\n", ft_strcmp(lst->path, lst->last_path));
		printf("rank = %d\n", lst->rank);
		if (ft_strcmp(lst->path, lst->last_path) != 0 && lst->rank >= 1)
			ft_putstr("\n");
		if (lst->rank > 0)
		{
			ft_putstr(lst->path);
			ft_putendl(":");
		}
		if (env.opt_l == 1)
			opt_l(lst->path, lst->file, env, 1);
		else
			print_tab(lst->file);
		lst = lst->prev;
	}
}
