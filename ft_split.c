/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:52:44 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/14 23:30:48 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

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
	//printf("trimed('%s', '%c'): '%s'\n", s, c, trimed);
	out = 0;
	// count number of 'char' inside the trimed string
	count = 0;
	while (trimed[out])
	{
		if (trimed[out] == c)
			count++;
		out++;
	}
	split = (char **) malloc((count + 2) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	count = 0;
	in = 0;
	out = 0;
	while (trimed[out])
	{
		if (trimed[out] == c)
		{
			split[count] = ft_substr(trimed, in, out - in);
			//printf("%d: '%s'\n", count, split[count]);
			if (split[count] == NULL)
				return (NULL);
			count++;
			in = out + 1; 
		}
		out++;
	}
	split[count] = ft_substr(trimed, in, out - in);
	//printf("%d: '%s'\n", count, split[count]);
	split[count + 1] = NULL;
	return (split);
}
