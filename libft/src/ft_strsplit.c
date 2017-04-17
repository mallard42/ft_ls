/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:57:35 by mallard           #+#    #+#             */
/*   Updated: 2016/11/30 17:16:08 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char		**ft_strcut(char **str, const char *s, char c)
{
	int			i;
	int			d;
	int			j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		d = i;
		if (s[i] != c)
		{
			while (s[d] != c && s[d] != '\0')
				d++;
			if (!(str[j] = ft_strnew(d - i)))
				return (NULL);
			d = 0;
			while (s[i] != c && s[i] != '\0')
				str[j][d++] = s[i++];
			j++;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	char		**str;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = ft_memalloc(sizeof(char *) * (ft_strcount(s, c) + 1))))
		return (NULL);
	str = ft_strcut(str, s, c);
	return (str);
}
