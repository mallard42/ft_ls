/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:46:40 by mallard           #+#    #+#             */
/*   Updated: 2016/11/30 17:11:27 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*temp;

	if (!s || !f)
		return (0);
	i = 0;
	if (!(temp = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	while (s[i])
	{
		temp[i] = (f)(s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
