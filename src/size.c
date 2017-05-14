/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:54:23 by mallard           #+#    #+#             */
/*   Updated: 2017/05/14 10:32:43 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_size      t_size_null(void)
{
	t_size		size;

	size.user = 0;
	size.group = 0;
	size.size_file = 0;
	size.link = 0;
	return (size);
}

t_size		ini_size(char **tab, char *str)
{
	int			i;
	struct stat	buf;
	t_size		size;

	i = 0;
	size = t_size_null();
	while (tab[i])
	{
		lstat(double_path(str, tab[i]), &buf);
		ini_user(buf, &size);
		i++;
	}
	return (size);
}

void		ini_user(struct stat buf, t_size *size)
{
	struct passwd   *user;
	struct group    *group;

	user = getpwuid(buf.st_uid);
	group = getgrgid(buf.st_gid);
	if (size->user < ft_strlen(user->pw_name))
		size->user = ft_strlen(user->pw_name);
	if (size->group < ft_strlen(group->gr_name))
		size->group = ft_strlen(group->gr_name);
	if (size->size_file < ft_intlen(buf.st_size))
		size->size_file = ft_intlen(buf.st_size);
	if (size->link < ft_intlen(buf.st_nlink))
		size->link= ft_intlen(buf.st_nlink);
}
