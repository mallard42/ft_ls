/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:37:10 by mallard           #+#    #+#             */
/*   Updated: 2017/05/14 18:20:12 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	is_link(char *str)
{
	struct stat		buf;
	int				ret;
	char			*link;
	char			*buff;

	lstat(str, &buf);
	if (S_ISLNK(buf.st_mode))
	{
		if ((buff = ft_strnew(32)))
		{
			//while ((ret = readlink(str, buff, 32)) != -1)
			//{
			ret = readlink(str, buff, 32);
			buff[ret] = '\0';
			link = ft_strjoin(link, buff);
			//}
			ft_putendl(link);
		}
	}
}

char	*info_time(t_opt env, struct stat buf)
{
	char	*tmp;

	tmp = NULL;
	if (env.opt_u == 1)
		tmp = ft_strsub(ctime(&(buf.st_atime)), 3, 13);
	else if (env.opt_maj_u == 1)
		tmp = ft_strsub(ctime(&(buf.st_birthtime)), 3, 13);
	else if (env.opt_c == 1)
		tmp = ft_strsub(ctime(&(buf.st_ctime)), 3, 13);
	else
		tmp = ft_strsub(ctime(&(buf.st_mtime)), 3, 13);
	tmp = ft_strjoin(tmp, " ");
	return (tmp);
}

void	opt_l(char *str, char **tab, t_opt env, int t)
{
	t_size		size;
	int			i;
	struct stat	buf;

	i = 0;
	size = ini_size(tab,str);
	if (t == 1)
		l_total(str,tab);
	while (tab[i])
	{
		lstat(double_path(str, tab[i]), &buf);
		print_l(tab[i], env, size, buf);
		i++;
	}
}

void		print_l(char *str, t_opt env, t_size size, struct stat buf)
{
	struct passwd	*user;
	struct group	*group;
	char			*tmp;

	user = getpwuid(buf.st_uid);
	group = getgrgid(buf.st_gid);
	mode_file(str, buf);
	print_space(ft_itoa((int)buf.st_nlink), size.link, 1);
	print_space(user->pw_name, size.user + 1, 0);
	print_space(group->gr_name, size.group + 2, 0);
	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
		maj_min(buf.st_dev);
	else
		print_space(ft_itoa((int)buf.st_size), size.size_file + 2, 1);
	tmp = info_time(env, buf);
	print_space(tmp, 11, 1);
	ft_putendl(str);
}

void		print_space(char *str, int size, int free)
{
	int		i;

	i = ft_strlen(str);
	while (i < size)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(str);
	if (free == 1)
		ft_strdel(&str);
}
