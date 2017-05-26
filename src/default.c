/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:03:37 by mallard           #+#    #+#             */
/*   Updated: 2017/05/26 10:27:11 by mallard          ###   ########.fr       */
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
	char	tmp;

	size = tablen(tab);
	while (i < size)
	{
		tab[i] = tab[i + 1];
		i++;
	}
}

void	dir_default(char **tab, t_opt env, t_dir **lst, int rank)
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
			error(tab[i], env);
		else
			tmp = opt_a(dir, tab[i], env);
		new = dirnew(tab[i], tmp, rank);
		if (*lst == NULL)
			*lst = dirnew(tab[i], tmp, rank);
		else
			diradd(lst, new);
		i++;
	}
}
