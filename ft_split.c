/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:09:10 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/15 15:22:18 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned int	words_count(char const *str, char c)
{
	unsigned int	i;
	unsigned int	flag;
	unsigned int	count;

	i = 0;
	flag = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && flag == 1)
		{
			flag = 0;
			count++;
		}
		else if (str[i] == c && flag == 0)
			flag = 1;
		i++;
	}
	return (count);
}

char	**make_split(char const *str, char c, char	**split)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	flag;
	char			**origin_p;

	origin_p = split;
	i = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] != c && flag == 1)
		{
			flag = 0;
			start = i;
		}
		else if (str[i] == c && flag == 0)
		{
			flag = 1;
			*split++ = ft_substr(str, start, (i - start));
		}
		i++;
	}
	*split++ = ft_substr(str, start, (i - start));
	*split = NULL;
	return (origin_p);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	char const		*str;
	char			set[2];
	char			**split;

	set[0] = c;
	set[1] = '\0';
	str = ft_strtrim(s, set);
	count = words_count(str, c);
	split = malloc((count + 1) * sizeof(char *));
	return (make_split(str, c, split));
}
