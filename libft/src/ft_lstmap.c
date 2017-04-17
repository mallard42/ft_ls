/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:34:33 by mallard           #+#    #+#             */
/*   Updated: 2016/11/30 13:35:03 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;

	if (!(new = (*f)(lst)))
		return (new);
	temp = new;
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			temp->next = NULL;
			return (new);
		}
		if (!(temp->next = (*f)(lst->next)))
			return (new);
		temp = temp->next;
		lst = lst->next;
	}
	return (new);
}
