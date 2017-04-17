/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:18:09 by mallard           #+#    #+#             */
/*   Updated: 2016/11/30 17:12:11 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*temp;

	if (!s && !f)
		return (0);
	i = 0;
	if (!(temp = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	while (s[i])
	{
		temp[i] = (f)(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
