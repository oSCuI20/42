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

	newlst = NULL;
	if (lst)
	{
		newlst = ft_lstnew(fn(lst->content));
		if (newlst)
		{
			lst = lst->next;
			while (lst)
			{
				ft_lstadd_back(&newlst, ft_lstnew(fn(lst->content)));
				lst = lst->next;
			}
			ft_lstclear(&lst, del);
		}
	}
	return (newlst);
}
