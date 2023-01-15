/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:37:58 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/08 23:37:59 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*fn)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	newlst = NULL;
	if (lst && fn)
	{
		newlst = ft_lstnew(fn(lst->content));
		if (newlst)
		{
			lst = lst->next;
			while (lst)
			{
				newnode = ft_lstnew(fn(lst->content));
				if (!newnode)
					break ;
				ft_lstadd_back(&newlst, newnode);
				lst = lst->next;
			}
			if (!newnode)
				ft_lstclear(&newlst, del);
		}
	}
	return (newlst);
}
