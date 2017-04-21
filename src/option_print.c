/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:37:10 by mallard           #+#    #+#             */
/*   Updated: 2017/04/21 20:03:34 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	l_total(char *str, char **tab)
{
	int				i;
	int				total;
	struct stat		buf;

	i = 0;
	total = 0;
	while (tab[i] != NULL)
	{
		lstat(double_path(str, tab[i]), &buf);
		total = total + buf.st_blocks;
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}

void	add_space(char **tab)
{
	int				i;
	int				j;
	int				k;

	j = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strlen(tab[i]) > j)
		{
			j = ft_strlen(tab[i]) + 1;
			i = -1;
		}
		else
		{
			k = ft_strlen(tab[i]);
			while (k != j)
			{
				tab[i] = ft_strjoin_f(" ", tab[i], 1);
				k++;
			}
		}
		i++;
	}
}

char	**info_time(char *str, char **tab, t_opt env)
{
	char			**tmp;
	int				i;
	struct stat		buf;

	i = 0;
	if (!(tmp = newtab(tablen(tab))))
		return (0);
	info_time_bonus(str, tab, env, tmp);	
	return (tmp);
}

void	info_time_bonus(char *str, char **tab, t_opt env, char **tmp)
{
	int				i;
	struct stat		buf;

	i = 0;
	if (env.opt_u == 1)
		while (tab[i] != NULL)
		{
			lstat(double_path(str, tab[i]), &buf);
			tmp[i] = ft_strsub(ctime(&(buf.st_atime)), 4, 12);
			tmp[i] = ft_strjoin_f(tmp[i], " ", 0);
			i++;
		}
	else if (env.opt_maj_u == 1)
		while (tab[i] != NULL)
		{
			lstat(double_path(str, tab[i]), &buf);
			tmp[i] = ft_strsub(ctime(&(buf.st_birthtime)), 4, 12);
			tmp[i] = ft_strjoin_f(tmp[i], " ", 0);
			i++;
		}
	else if (env.opt_c == 1)
		while (tab[i] != NULL)
		{
			lstat(double_path(str, tab[i]), &buf);
			tmp[i] = ft_strsub(ctime(&(buf.st_ctime)), 4, 12);
			tmp[i] = ft_strjoin_f(tmp[i], " ", 0);
			i++;
		}
	else
		while (tab[i] != NULL)
		{
			lstat(double_path(str, tab[i]), &buf);
			tmp[i] = ft_strsub(ctime(&(buf.st_mtime)), 4, 12);
			tmp[i] = ft_strjoin_f(tmp[i], " ", 0);
			i++;
		}
}

void	info_link(char *str, char **tab, char ***info)
{
	int				i;
	struct stat		buf;

	i = -1;
	if ((info[0] = newtab(tablen(tab))))
	{
		while (tab[++i] != NULL)
		{
			lstat(double_path(str, tab[i]), &buf);
			info[0][i] = ft_itoa((int)buf.st_nlink);
			info[0][i] = ft_strjoin_f(info[0][i], " ", 0);
		}
		add_space(info[0]);
	}
	i = -1;
	if ((info[3] = newtab(tablen(tab))))
	{
		while (tab[++i] != NULL)
		{
			lstat(double_path(str, tab[i]), &buf);
			info[3][i] = ft_itoa((int)buf.st_size);
			info[3][i] = ft_strjoin_f(info[3][i], " ", 0);
		}
		add_space(info[3]);
	}
}

void	info_user(char *str, char **tab, char ***info)
{
	int				i;
	struct stat		buf;
	struct passwd	*user;
	struct group	*group;

	i = -1;
	if ((info[1] = newtab(tablen(tab))))
	{
		while (tab[++i] != NULL)
		{
			lstat(double_path(str, tab[i]), &buf);
			user = getpwuid(buf.st_uid);
			info[1][i] = ft_strdup(user->pw_name);
			info[1][i] = ft_strjoin_f(info[1][i], " ", 0);
		}
		add_space(info[1]);
	}
	i = -1;
	if ((info[2] = newtab(tablen(tab))))
	{
		while (tab[++i] != NULL)
		{
			lstat(double_path(str, tab[i]), &buf);
			group = getgrgid(buf.st_gid);
			info[2][i] = ft_strdup(group->gr_name);
			info[2][i] = ft_strjoin_f(info[2][i], " ", 0);
		}
		add_space(info[2]);
	}
}

void	opt_l(char *str, char **tab, t_opt env, int t)
{
	char			***tmp;
	int				i;

	i = 0;
	if ((tmp = (char ***)malloc(sizeof(char **) * 7)))
	{
		info_link(str, tab, tmp);
		info_user(str, tab, tmp);
		tmp[4] = info_time(str, tab, env);
		tmp[5] = tab;
		tmp[6] = NULL;
		if (t == 1)
			l_total(str, tab);
		while (i < tablen(tab))
		{
			mode_file(double_path(str, tab[i]));
			ft_putstr(tmp[0][i]);
			ft_putstr(tmp[1][i]);
			ft_putstr(tmp[2][i]);
			ft_putstr(tmp[3][i]);
			ft_putstr(tmp[4][i]);
			ft_putendl(tmp[5][i]);
			i++;
		}
	}
}
void	mode_file(char *str)
{
	struct stat		buf;

	lstat(str, &buf);
	if (S_ISREG(buf.st_mode))
		ft_putstr("-");
	else if (S_ISLNK(buf.st_mode))
		ft_putstr("l");
	if (S_ISDIR(buf.st_mode))
		ft_putstr("d");
	ft_putstr((buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((buf.st_mode & S_IXOTH) ? "x" : "-");

}
