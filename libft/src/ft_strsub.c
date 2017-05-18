/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:31:53 by mallard           #+#    #+#             */
/*   Updated: 2016/12/01 11:09:54 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	j = (size_t)start;
	i = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < len && s[j] != '\0')
	{
		str[i] = s[j];
		i++;
		j++;
	}
	return (str);
}
