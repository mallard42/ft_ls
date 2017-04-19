/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:48:27 by mallard           #+#    #+#             i*/
/*   Updated: 2017/04/19 18:16:53 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	check_option(char *str, char *option)
{
	int				i;
	int				j;

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

void	check_file(char **tab, t_opt env)
{
	int				i;
	struct stat		buf;
	char			**tmp;
	t_dir			*new;

	i = 0;
	if ((tmp = newtab(0)))
	{
		while (tab[i] != NULL)
		{
			lstat(tab[i], &buf);
			if (S_ISREG(buf.st_mode))
			{
				add_str_to_tab(tmp, tab[i]);
				char_del(tab, i);
			}
			i++;
		}
		if (tmp != NULL)
		{
			new = dirnew("", tmp);
			if (new != NULL)
			{
				option_sort(env, new, 0, tmp);
				print_tab(tmp);
			}
		}
	}
}
