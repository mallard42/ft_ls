/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:16:35 by mallard           #+#    #+#             */
/*   Updated: 2016/12/19 18:16:41 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_strcount(char const *s, char c)
{
	int			i;
	int			result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c || s[i + 1] == '\0') && s[i + 1] != c)
			result++;
		i++;
	}
	return (result);
}
