/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:23:49 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/14 23:34:01 by nefimov          ###   ########.fr       */
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
void ft_strjoin_test(void)
{
	char			*s1[3] = {"", "s1", "ABCD_"};
	char			*s2[3] = {"", "s2", "0123456789"};
	char			*join;
	unsigned int	num = 3;
	unsigned int	i;
	unsigned int	j;
	
	printf("\n---- <ft_strjoin> ----\n\n");
	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			join = ft_strjoin(s1[i], s2[j]);
			printf("ft_strjoin(%s, %s): %s\n\n", s1[i], s2[j], join);
			free(join);
			j++;
		}
		i++;
	}	
}

void	ft_strtrim_test(void)
{
	char			*s1[3] = {"", "1234567890", "ABCD_"};
	char			*set[3] = {"", "2109", "4567A"};
	char			*trim;
	unsigned int	num = 3;
	unsigned int	i;
	unsigned int	j;
	
	printf("\n---- <ft_strtrim> ----\n\n");
	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			trim = ft_strtrim(s1[i], set[j]);
			printf("ft_strtrim(%s, %s): %s\n\n", s1[i], set[j], trim);
			free(trim);
			j++;
		}
		i++;
	}	
}
void	ft_split_test(void)
{
	char			*s1[3] = {"  ", " 123  4567 890a", "AB5CD_5"};
	char			*set = "a 5";
	char			**split;
	unsigned int	num = 3;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	
	printf("\n---- <ft_split> ----\n\n");
	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			printf("\n%d%d\n", i, j);
			split = ft_split(s1[i], set[j]);
			printf("ft_split('%s', '%c'):\n", s1[i], set[j]);
			k = 0;
			while (split[k] != NULL)
			{
				printf("%d: '%s'\n", k, split[k]);
				free(split[k]);
				k++;				
			}
			free(split[k]);
			free(split);
			j++;
		}
		i++;
	}	
}

int	main(void)
{
	/* ft_substr_test();
	ft_strjoin_test(); 
	ft_strtrim_test(); */
	ft_split_test();
	
	return (0);
}