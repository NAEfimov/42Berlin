/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:31:54 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/17 17:05:02 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	
	if (s == NULL || f == NULL)
		return;
	i = 0;
	while (s[i])
	{
		//printf("s[%d]: %c\n", i, s[i]);
		f(i, s);
		//printf("s[%d]: %c\n", i, s[i]);
		i++;
	}
	return;
}