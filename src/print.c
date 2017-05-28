/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:47:08 by mallard           #+#    #+#             */
/*   Updated: 2017/05/28 19:59:02 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		print_multi_str(int i, int size, t_dir **lst, int file)
{
	size = size + file;
	if ((*lst)->path != NULL && size > 1)
	{
		ft_putstr((*lst)->path);
		ft_putendl(":");
	}
	print_tab((*lst)->file);
	if (i < size - file)
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
	char	*tmp;

	if (str == NULL)
		return (NULL);
	i = ft_strlen(str) - 1;
	if (i == 0)
		return (str);
	while (str[i] && str[i] != '/')
		i--;
	if (!ft_strrchr(str, '/'))
		return (str);
	tmp = ft_strsub(str, 0, i);
	return (path_sup(tmp));
}

void		print_rank(t_opt env, t_dir *lst, int size)
{
	if (lst->rank > 0)
		ft_putstr("\n");
	if (lst->rank > 0 || lst->prev)
	{
		ft_putstr(lst->path);
		ft_putendl(":");
	}
	if (env.opt_l == 1)
		opt_l(lst->path, lst->file, env, 1);
	else
		print_tab(lst->file);
}
