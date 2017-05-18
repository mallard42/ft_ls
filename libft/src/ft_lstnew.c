/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:54:47 by mallard           #+#    #+#             */
/*   Updated: 2016/12/16 12:10:29 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if (!(new_list = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		return (new_list);
	}
	if (!(new_list->content = ft_memalloc(content_size)))
		return (NULL);
	ft_memcpy(new_list->content, content, content_size);
	new_list->content_size = content_size;
	new_list->next = NULL;
	return (new_list);
}
