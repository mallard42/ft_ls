/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:07:47 by mallard           #+#    #+#             */
/*   Updated: 2017/04/18 17:52:12 by mallard          ###   ########.fr       */
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

int		sizelst(t_dir **file)
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

int			size_dir(char *str, int a)
{
	DIR				*dir;
	int				i;
	struct dirent	*sd;

	i = 0;
	dir = opendir(str);
	if (dir == NULL)
		return (0);
	while ((sd = readdir(dir)) != NULL)
	{
		if (a == 1)
			i++;
		else
		{
			if (sd->d_name[0] != '.')
				i++;
		}
	}
	closedir(dir);
	return (i);
}
