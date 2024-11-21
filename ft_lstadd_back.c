/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:26:06 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/21 15:47:35 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
		return;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->next = NULL;
	}
}