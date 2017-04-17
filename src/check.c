/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:48:27 by mallard           #+#    #+#             i*/
/*   Updated: 2017/04/17 14:52:58 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	check_option(char *str, char *option)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (str[i] != '\0' && option[j] != '\0')
	{
		if (str[i] == option[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	if (option[j] == '\0' && str[i] != '\0')
		error_option(str[i]);
}
