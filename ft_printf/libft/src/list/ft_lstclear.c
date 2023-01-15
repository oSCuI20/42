/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:37:32 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/08 23:37:40 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		ft_lstdelone(tmp1, del);
		tmp1 = tmp2;
	}
	*lst = NULL;
}
