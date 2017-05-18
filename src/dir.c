/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:07:47 by mallard           #+#    #+#             */
/*   Updated: 2017/05/18 18:20:09 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_dir		*dirnew(char *path, char **file)
{
	t_dir			*new;

	new = (t_dir *)malloc(sizeof(t_dir));
	if (!new)
		return (0);
	new->file = file;
	new->path = path;
	new->rank = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		diradd(t_dir **file, t_dir *new)
{
	if (new && *file && file)
	{
		new->next = *file;
		new->prev = NULL;
		(*file)->prev = new;
		startdir(file);
	}
}

int			sizelst(t_dir **file)
{
	int		i;

	i = 0;
	startdir(file);
	while ((*file)->next != NULL)
	{
		*file = (*file)->next;
		i++;
	}
	return (i + 1);
}

void		startdir(t_dir **file)
{
	while ((*file)->prev != NULL)
		*file = (*file)->prev;
}

int			is_end(char *path, char *str)
{
	DIR				*dir;
	int				i;
	struct dirent	*sd;
	char			**tmp;
	struct stat		buf;

	dir = opendir(path);
	if (!(tmp = newtab(1)) || dir == NULL)
		return (-1);
	tmp[0] = NULL;
	while ((sd = readdir(dir)) != NULL)
	{
		lstat(double_path(str, sd->d_name), &buf);
		if (S_ISDIR(buf.st_mode) && ft_strncmp(sd->d_name, ".", 1))
		{
			if (tmp[0] == NULL)
				tmp[0] = double_path(path, sd->d_name);
			else
				tmp = add_str_to_tab(tmp, double_path(path, sd->d_name));
		}
	}
	closedir(dir);
	i = tablen(tmp) - 1;
	printf("tmp = %s\n", tmp[i]);
	return (ft_strcmp(tmp[i] , str)) ? 0 : 1;
}
