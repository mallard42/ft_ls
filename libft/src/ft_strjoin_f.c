/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:30:19 by mallard           #+#    #+#             */
/*   Updated: 2017/03/17 10:36:06 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strjoin_f(char *s1, char *s2, int nbr)
{
	char	*str;
	int		i;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	str[i] = '\0';
	if (nbr == 1 || nbr == 2)
		ft_strdel(&s2);
	if (nbr == 0 || nbr == 2)
		ft_strdel(&s1);
	return (str);
}
