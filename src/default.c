/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:03:37 by mallard           #+#    #+#             */
/*   Updated: 2017/06/20 15:48:59 by mallard          ###   ########.fr       */
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
	i = 0;
	while (tab[i] != NULL)
	{
		tmp = NULL;
		if ((dir = opendir(tab[i])) == NULL)
			tmp = error(tab[i]);
		else
		{
			tmp = opt_a(dir, tab[i], env);
			closedir(dir);
		}
		new = dirnew(tab[i], tmp, rank);
		if (*lst == NULL)
			*lst = dirnew(tab[i], tmp, rank);
		else
			diradd(lst, new);
		i++;
		rank++;
	}
}
