/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:03:33 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/21 15:27:40 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_lst;
	t_list	*cur_lst;

	if (del == NULL)
		return ;
	cur_lst = *lst;
	while (cur_lst->next)
	{
		next_lst =  cur_lst->next;
		del(cur_lst->content);
		free(cur_lst);
		cur_lst = next_lst;
	}
	del(cur_lst->content);
	free(cur_lst);	
}