/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:46:28 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/14 14:33:58 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		cplen;
	size_t		slen;
	char		*fd;
	
	slen = ft_strlen(s);
	if (start > slen)
		return (NULL);
	cplen = 0;
	while (s[start + cplen] && len > 0)
	{
		cplen++;
		len--;
	}
	fd = (char *) malloc((cplen + 1) * sizeof(char));
	if (fd != NULL)
	{
		i = 0;
		while (i < cplen)
		{
			fd[i] = s[start + i];
			i++;
		}
		fd[i] = '\0';
	}
	return (fd);
}