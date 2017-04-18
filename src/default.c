/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:03:37 by mallard           #+#    #+#             */
/*   Updated: 2017/04/18 18:28:35 by mallard          ###   ########.fr       */
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
		printf("1\n");
		dir = opendir(tab[i]);
		printf("2\n");
		if (dir == NULL)
		{
			printf("a\n");
			error(tab[i]);
		}
		else
		{
			printf("b\n");
			tmp = opt_a(dir, tab[i], env);
		}
		printf("3\n");
		//default_sort(tmp);
		printf("4\n");
		new = dirnew(tab[i], tmp);
		printf("1\n");
		if (*lst == NULL)
			*lst = dirnew(tab[i], tmp);
		else
			diradd(lst, new);
		i++;
	}
}
