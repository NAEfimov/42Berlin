/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:52:44 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/14 19:17:08 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char			**split;
	char			set[2];
	char			*trimed;
	unsigned int	in;
	unsigned int	out;
	unsigned int	count;

	set[0] = c;
	set[1] = '\0';
	trimed = ft_strtrim(s, set);
	in = 0;
	out = ft_strlen(trimed);
	// count number of 'char' inside the trimed string
	count = 0;
	while (*trimed)
	{
		
	}
	while (trimed[out])
	{
		if (trimed[out == c])
		{
			
		}
		out++;
	}
}