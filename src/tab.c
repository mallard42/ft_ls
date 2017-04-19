/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:35:43 by mallard           #+#    #+#             */
/*   Updated: 2017/04/19 18:19:19 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char	**newtab(int size)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	tab[size] = NULL;
	return (tab);
}

void	print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		i++;
	}
}

int		tablen(char **tab)
{
	int		i;

	i = 0;
	if (!tab && !*tab)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**add_str_to_tab(char **tab, char *str)
{
	char	**tmp;
	int		i;

	i = tablen(tab);
	if (tab[0] == NULL)
		i = 1;
	if (!(tmp = newtab(i + 1)))
		return (0);
	i = 0;
	while (tab[i] != NULL)
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	printf("i = %d\n", i);
	printf("str = %s\n", str);
	tmp[i] = ft_strdup(str);
	printf("tab[i] = %s\n", tab[i]);
	return (tmp);
}

char	**del_str_to_tab(char **tab, int j)
{
	char	**tmp;
	int		i;

	i = 0;
	while (tab[j] != NULL && tab[j][0] == '-')
		j++;
	if (j == tablen(tab))
	{
		if (!(tmp = newtab(1)))
			return (0);
		tmp[0] = ft_strdup(".");
	}
	else
	{
		if (!(tmp = newtab(tablen(tab) - j)))
			return (0);
		while (j < tablen(tab))
		{
			tmp[i] = tab[j];
			i++;
			j++;
		}
	}
	default_sort(tmp);
	return (tmp);
}
