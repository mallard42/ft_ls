/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:03:37 by mallard           #+#    #+#             */
/*   Updated: 2017/04/19 15:24:19 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	default_sort(char **file)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = NULL;
	while (file[i] != NULL && file[i + 1] != NULL)
	{
		if (ft_strcmp(file[i], file[i + 1]) > 0)
		{
			tmp = file[i];
			file[i] = file[i + 1];
			file[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	char_del(char **tab, int i)
{
	int		size;

	size = tablen(tab);
	//ft_strdel(&tab[i]);
	while (i < size)
	{
		tab[i] = tab[i + 1];
		i++;
	}
}

void	dir_default(char **tab, t_opt env, t_dir **lst)
{
	t_dir	*new;
	int		i;
	DIR		*dir;
	char	**tmp;

	*lst = NULL;
	tmp = NULL;
	i = 0;
	while (tab[i] != NULL)
	{
		dir = opendir(tab[i]);
		if (dir == NULL)
			error(tab[i]);
		else
			tmp = opt_a(dir, tab[i], env);
		//default_sort(tmp);
		new = dirnew(tab[i], tmp);
		if (*lst == NULL)
			*lst = dirnew(tab[i], tmp);
		else
			diradd(lst, new);
		i++;
	}
}
