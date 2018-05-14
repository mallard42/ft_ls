/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:48:27 by mallard           #+#    #+#             */
/*   Updated: 2017/06/21 15:33:48 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char	*check_lnk(char *str)
{
	struct stat		buf;
	char			*link;
	char			*buff;
	int				ret;

	lstat(str, &buf);
	link = NULL;
	if (S_ISLNK(buf.st_mode))
	{
		if ((ret = readlink(str, buff, 1096)) != -1)
		{
			buff[ret] = '\0';
			link = ft_strjoin(link, buff);
			str = link;
		}
	}
	return (str);
}

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

char	**check_file(char **tab)
{
	int				i;
	struct stat		buf;
	char			**tmp;

	i = -1;
	if (!(tmp = newtab(1)))
		return (0);
	tmp[0] = NULL;
	while (tab[++i] != NULL)
	{
		lstat(tab[i], &buf);
		if (S_ISDIR(buf.st_mode) == 0 && S_ISLNK(buf.st_mode) == 0)
		{
			if (tmp[0] == NULL)
				tmp[0] = ft_strdup(tab[i]);
			else
				tmp = add_str_to_tab(tmp, tab[i]);
			char_del(tab, i--);
		}
	}
	return (tmp);
}

int		check_mode(char *str, t_opt env)
{
	DIR				*dir;
	int				i;

	i = 0;
	if (str)
	{
		dir = opendir(str);
		i = (dir == NULL) ? 0 : 1;
		if (dir)
			closedir(dir);
	}
	return (i);
}

int		check_tab(char **tab)
{
	struct stat		buf;
	int				i;
	int				error;

	error = 0;
	if (*tab)
	{
		i = 0;
		while (tab[i])
		{
			lstat(tab[i], &buf);
			if (errno == ENOENT)
			{
				error++;
				error_comp(tab[i], tab, &i);
			}
			i++;
		}
	}
	return (error);
}
