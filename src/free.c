/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:10:42 by mallard           #+#    #+#             */
/*   Updated: 2017/05/24 18:25:02 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	dirfree_end(t_dir **lst)
{
	t_dir	*tmp;

	tmp = *lst;
	lst = &((*lst)->prev);
	tabdel(tmp->file);
	tmp->path = NULL;
	free(tmp);
	tmp = NULL;
}

void	tabdel(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_strdel(&(tab[i]));
		i++;
	}
	free(tab);
	tab = NULL;
}
