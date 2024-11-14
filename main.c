/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:23:49 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/14 14:41:48 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void ft_substr_test(void)
{
	char			*s = "0123456789";
	char			*dest;
	unsigned int	start;
	unsigned int	str;
	size_t			len;
	size_t			l;
	
	printf("\n---- <ft_substr> ----\n\n");
	start = 12;
	len = 12;
	str = 0;
	while (str <= start)
	{
		l = 0;
		while (l <= len)
		{
			dest = ft_substr(s, str, l);
			printf("ft_substr(%s, %d, %d): %s\n\n", s, str, (int) l, dest);
			free(dest);
			l += 3;
		}
		str += 3;
	}
	
}

int	main(void)
{
	ft_substr_test();
	return (0);
}