/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 11:27:15 by mallard           #+#    #+#             */
/*   Updated: 2017/04/18 13:40:50 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char	*double_path(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	if (ft_strcmp(s1, "/"))
		str = ft_strjoin(s1, "/");
	str = ft_strjoin(str, s2);
	return (str);
}

void	ft_single_path(char *s1, int i)
{
	if (i != 0)
		ft_putchar('\n');
	ft_putstr(s1);
	ft_putendl(":");
}
