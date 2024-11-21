/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:05:05 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/21 15:49:55 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	// t_list	*next;
	t_list	*lstmap;
	t_list	*new;

	if (*f == NULL || f == NULL || del == NULL || lst == NULL)
		return NULL;
	lstmap = NULL;
	while (lst->next)
	{
		// next = lst->next;
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			// Clear list;
			return (NULL);
		}
		if (lstmap == NULL)
			lstmap = new;	
		
	}
	return (lstmap);
}
