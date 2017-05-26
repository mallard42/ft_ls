/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:07:47 by mallard           #+#    #+#             */
/*   Updated: 2017/05/26 16:01:06 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_dir		*dirnew(char *path, char **file, int rank)
{
	t_dir			*new;

	new = (t_dir *)malloc(sizeof(t_dir));
	if (!new)
		return (0);
	new->file = file;
	new->path = path;
	new->last_path = path_sup(path);
	new->rank = rank;
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

char		*last_dir(char *path)
{
	DIR				*dir;
	struct dirent	*sd;
	char			*tmp;
	struct stat		buf;

	if (path == NULL)
		return (NULL);
	tmp = NULL;
	dir = opendir(path);
	while ((sd = readdir(dir)) != NULL)
	{
		lstat(double_path(path, sd->d_name), &buf);
		if (errno == EACCES)
			single_error(path);
		else if (S_ISDIR(buf.st_mode) && ft_strncmp(sd->d_name, ".", 1))
			tmp = double_path(path, sd->d_name);
	}
	closedir(dir);
	return (tmp) ? last_dir(tmp) : path;
}
