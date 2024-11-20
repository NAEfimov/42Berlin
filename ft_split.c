/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:09:10 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/20 17:49:09 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* static void	clear_split(char	**split)
{
	unsigned int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
}
 */
static unsigned int	words_count(char const *str, char c)
{
	unsigned int	i;
	unsigned int	flag;
	unsigned int	count;

	i = 0;
	flag = 1;
	count = 0;
	while (str[i] == c)
		i++;
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
	if (flag == 0)
		count++;
	return (count);
}

static void	make_split(char const *str, char c, char **split)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	flag;

	i = 0;
	flag = 1;
	while (str[i] && str[i] == c)
		i++;
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
			if (*split - 1 == NULL)
			return ;
		}
		i++;
	}
	if (flag == 0)	
		*split++ = ft_substr(str, start, (i - start));
	if (*split - 1 == NULL)
		return ;
	*split = NULL;
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	char			**split;

	count = words_count(s, c);
	split = malloc((count + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	if (count == 0)
		*split = NULL;
	else
		make_split(s, c, split);
	return (split);
}
