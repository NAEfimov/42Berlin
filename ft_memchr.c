/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:15:48 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/19 19:04:58 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	str = (char *) s;
	while (n > 0)
	{
		if (*str == c % 256)
			return ((void *) str);
		str++;
		n--;
	}
	return (NULL);
}
