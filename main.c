/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:23:26 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/17 17:11:27 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.a"
#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

void	ft_isalpha_test(char *str)
{
	printf("--- <ft_isalpha> ---\n\n");
	while (*str)
	{
		printf("ft_isalpha(%c):\t%i\n", *str, ft_isalpha(*str));
		printf("isalpha(%c):\t%i\n\n", *str, isalpha(*str));
		str++;
	}
}
void	ft_isdigit_test(char *str)
{
	printf("--- <ft_isdigit> ---\n\n");
	while (*str)
	{
		printf("ft_isdigit(%c):\t%i\n", *str, ft_isdigit(*str));
		printf("isdigit(%c):\t%i\n\n", *str, isdigit(*str));
		str++;
	}
}
void	ft_isalnum_test(char *str)
{
	printf("--- <ft_isalnum> ---\n\n");
	while (*str)
	{
		printf("ft_isalnum(%c):\t%i\n", *str, ft_isalnum(*str));
		printf("isalnum(%c):\t%i\n\n", *str, isalnum(*str));
		str++;
	}
}
void	ft_isascii_test(char *str)
{
	printf("--- <ft_isascii> ---\n\n");
	while (*str)
	{
		printf("ft_isascii(%c):\t%i\n", *str, ft_isascii(*str));
		printf("isascii(%i):\t%i\n\n", *str, isascii(*str));
		str++;
	}
	printf("ft_isascii(%c):\t%i\n", -1, ft_isascii(-1));
	printf("isascii(%i):\t%i\n\n", -1, isascii(-1));
	printf("ft_isascii(%c):\t%i\n", 128, ft_isascii(128));
	printf("isascii(%i):\t%i\n\n", 128, isascii(128));
}
void	ft_isprint_test(void)
{
	// num must ends with negative value
	int	num[6] = {31, 32, 100, 126, 127, -1};
	int i;
	
	printf("--- <ft_isprint> ---\n\n");
	i = -1;
	while (num[++i] >= 0)
	{
		printf("ft_isprint(%c):\t%i\n", num[i], ft_isprint(num[i]));
		printf("isprint(%i):\t%i\n\n", num[i], isprint(num[i]));
	}
}
void	ft_strlen_test(void)
{
	int		n = 3;
	char	*str[3];
	
	str[0] = "";
	str[1] = "1234567";
	str[2] = "aBcDeFgHi";
	printf("--- <ft_strlen> ---\n\n");
	while (--n >= 0)
	{
		printf("ft_strlen(%s):\t%d\n", str[n], (int) ft_strlen(str[n]));
		printf("strlen(%s):\t%d\n\n", str[n], (int) strlen(str[n]));
	}
}
void	ft_memset_test()
{
	
}
void	ft_bzero_test(void)
{
	char	str[] = "12345";
	
	printf("--- <ft_bzero> ---\n\n");
	printf("ft_bzero(%s, %i): ", str, 2);
	ft_bzero(str + 3, (size_t) 2);
	printf("%s\n\n", str);

}
void	ft_memcpy_test(void)
{
	char	str[10] = "123456789";
	char	dest[9] = "aaaaaa";
	
	printf("--- <ft_memcpy> ---\n\n");
	printf("str: %s\n", str);
	printf("dest: %s\n", dest);
	ft_memcpy(dest + 2, str, 3);
	printf("memcpy(dest, str, %i): %s\n", 3, dest);
}
void	ft_memmove_test(void)
{
	char	str[30] = "123456789abcdefghijklmnopq";
	char	*dest;
	
	printf("\n--- <ft_memmove> ---\n\n");
	dest = str + 20;
	printf("str: %s\n", str);
	printf("dest: %s\n", dest);
	ft_memmove(dest, str + 8, 7);
	printf("memmove(dest, str, %i): %s\n", 7, dest);
}
size_t	strlcpy(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;

	/* Copy as many bytes as will fit */
	if (n != 0) {
		while (--n != 0) {
			if ((*d++ = *s++) == '\0')
				break;
		}
	}

	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0) {
		if (siz != 0)
			*d = '\0';		/* NUL-terminate dst */
		while (*s++)
			;
	}

	return(s - src - 1);	/* count does not include NUL */
}
size_t	strlcat(char *dst, const char *src, size_t siz)
{
	register char *d = dst;
	register const char *s = src;
	register size_t n = siz;
	size_t dlen;

	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return(dlen + strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));
}
void	ft_strlcat_test(void)
{
	char 	src[20] = "ABCDE";
	char 	dst[30] = "abcdefghjk";
	size_t	size[] = {0, 2, 5, 10, 12, 15, 10000};
	int		i;
	
	printf("src: %s\ndst: %s\n", src, dst);
	printf("dst_len: %i\nsrc_len: %i\n\n", (int) ft_strlen(dst), (int) ft_strlen(src));
	i = -1;
	while (size[++i] < 100)
	{
		printf("src: %s\ndst: %s\nsize: %d\n", src, dst, (int) size[i]);
		printf("ft_strlcat(dst, src, size): %d\n", (int) ft_strlcat(dst, src, size[i]));
		printf("src: %s\ndst: %s\n\n", src, dst);
	}
}
void	ft_strlcpy_test(void)
{
	char 	src[20] = "123456789ABCDEFGHIJK";
	char 	dst[30] = "abcdefghjk";
	size_t	size[] = {0, 1, 2, 5, 10, 12, 21, 10000};
	int		i;
	
	printf("src: %s\ndst: %s\n", src, dst);
	printf("dst_len: %i\nsrc_len: %i\n\n", (int) ft_strlen(dst), (int) ft_strlen(src));
	i = -1;
	while (size[++i] < 100)
	{
		//printf("src: %s\ndst: %s\nsize: %d\n", src, dst, (int) size[i]);
		printf("ft_strlcpy(dst, src, %d): %d\n", (int) size[i], (int) ft_strlcpy(dst, src, size[i]));
		printf("src: %s\ndst: %s\n\n", src, dst);
	}
}
void	ft_toupper_test(char *str)
{
	printf("--- <ft_toupper> ---\n\n");
	while (*str)
	{
		printf("ft_toupper(%c):\t%c\n", *str, ft_toupper(*str));
		printf("toupper(%c):\t%c\n\n", *str, toupper(*str));
		str++;
	}
}
void	ft_tolower_test(char *str)
{
	printf("--- <ft_tolower> ---\n\n");
	while (*str)
	{
		printf("ft_tolower(%c):\t%c\n", *str, ft_tolower(*str));
		printf("tolower(%c):\t%c\n\n", *str, tolower(*str));
		str++;
	}
}
void	ft_strchr_test(void)
{
	char	*str = "abcde1234abcdf";
	char	*chr = "c2Gf";
	
	printf("\n--- <ft_strchr> ---\n\n");
	printf("str:\t\t\t%s\n", str);
	printf("*str:\t\t\t%p\n", str);
	while (*chr)
	{
		printf("ft_strchr(str, %c):\t%p\n", *chr, ft_strchr(str, *chr));
		printf("strchr(str, %c):\t\t%p\n", *chr, strchr(str, *chr));
		chr++;
	}
	printf("ft_strchr(str, %c):\t%p\n", *chr, ft_strchr(str, '\0'));
	printf("strchr(str, %c):\t\t%p\n", *chr, strchr(str, '\0'));
}
void	ft_strrchr_test(void)
{
	char	*str = "abcde1234abcdf";
	char	*chr = "ec2Gf";
	
	printf("\n--- <ft_strrchr> ---\n\n");
	printf("str:\t\t\t%s\n", str);
	printf("*str:\t\t\t%p\n\n", str);
	while (*chr)
	{
		printf("ft_strrchr(str, %c):\t%p\n", *chr, ft_strrchr(str, *chr));
		printf("strrchr(str, %c):\t%p\n", *chr, strrchr(str, *chr));
		chr++;
	}
	printf("ft_strrchr(str, %c):\t%p\n", *chr, ft_strrchr(str, '\0'));
	printf("strrchr(str, %c):\t\t%p\n", *chr, strrchr(str, '\0'));
}
void	ft_strncmp_test(void)
{
	const char 	*str1 = "12d456789";
	const char 	*str2 = "12abcdef";
	size_t		n[] = {0, 1, 2, 3, 9, 1000000};
	int			i = 0;
	
	printf("\n--- <ft_strncmp> ---\n\n");
	while (n[i] < 10000)
	{
		printf("ft_strncmp(str1, str2, %d):\t%i\n", (int) n[i], ft_strncmp(str1, str2, n[i]));
		printf("strncmp(str1, str2, %d):\t\t%i\n\n", (int) n[i], strncmp(str1, str2, n[i]));
		i++;
	}
}
void	ft_memchr_test(void)
{
	char	*str = "abcde1234abcdf";
	char	*chr = "c2Gf";
	size_t	i;
	
	i = 0;
	printf("\n--- <ft_memchr> ---\n\n");
	printf("str:\t\t\t%s\n", str);
	printf("*str:\t\t\t%p\n", str);
	while (i < 10)
	{
		
		while (*chr)
		{
			printf("ft_memchr(str, %c, %i):\t%p\n", *chr, (int) i, ft_memchr(str, *chr, i));
			printf("memchr(str, %c, %i):\t%p\n\n", *chr, (int) i, memchr(str, *chr, i));
			chr++;
		}
		chr = chr - 5;
		i++;
	}	
}
void	ft_memcmp_test(void)
{
	const char 	*str1 = "123456789";
	const char 	*str2 = "12abcdef";
	size_t		n[] = {0, 1, 2, 3, 9, 1000000};
	int			i = 0;
	
	printf("\n--- <ft_memcmp> ---\n\n");
	while (n[i] < 10000)
	{
		printf("ft_memcmp(str1, str2, %d):\t%i\n", (int) n[i], ft_memcmp(str1, str2, n[i]));
		printf("memcmp(str1, str2, %d):\t\t%i\n\n", (int) n[i], memcmp(str1, str2, n[i]));
		i++;
	}
}
void	ft_strnstr_test(void)
{
	const char 	*str1 = "12d456789";
	const char 	*str2 = "2d45678900";
	size_t		n[] = {0, 1, 2, 3, 14, 1000000};
	int			i = 0;
	
	printf("\n--- <ft_strnstr> ---\n\n");
	printf("big:\t\t\t%s\n", str1);
	printf("little:\t\t\t%s\n", str2);
	printf("*big:\t\t\t%p\n\n", str1);
	
	while (n[i] < 10000)
	{
		printf("ft_strnstr(str1, str2, %d):\t%p\n", (int) n[i], ft_strnstr(str1, str2, n[i]));
		//printf("strnstr(str1, str2, %d):\t\t%p\n\n", (int) n[i], strnstr(str1, str2, n[i]));
		i++;
	}
}
void	ft_atoi_test(void)
{
	int		n = 5;
	char	*str[5];
	
	str[0] = "";
	str[1] = "1234567";
	str[2] = "0";
	str[3] = "\v   -54366asdad";
	str[4] = "   sa 34556  fgdg";
	printf("--- <ft_atoi> ---\n\n");
	while (--n >= 0)
	{
		printf("ft_atoi(%s):%d\n", str[n], (int) ft_atoi(str[n]));
		//printf("atoi(%s):\t%d\n\n", str[n], (int) atoi(str[n]));
	}
}
void	ft_calloc_test(void)
{
	void	*str;
	char	*s;
	size_t		num;
	
	printf("\n--- <ft_atoi> ---\n\n");
	num = 10;
	str = ft_calloc(num, sizeof(char));
	s = (char *) str;
	s[0] = 'a';
	s[2] = 'b';
	printf("srt: %s\n", (char *) str);
	free(str);
}
void	ft_strdup_test(void)
{
	char	*s[3] = {"123", "", "advbgnn"};
	char	*str;
	int		i;
	
	printf("\n--- <ft_strdup> ---\n\n");
	i = 0;
	while (i < 3)
	{
		printf("s: '%s' %p\n", s[i], s[i]);
		str = ft_strdup(s[i]);
		printf("ft_strdup: '%s' %p\n\n", str, str);
		free(str);
		i++;
	}
}
void	ft_substr_test(void)
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
void	ft_strjoin_test(void)
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
void	ft_itoa_test(void)
{
	char	*s;
	int		num[] = {1, 0, -1, 123456, -123456, INT_MAX, INT_MIN};
	int		i;
	int		j;
	
	i = 0;
	while (i < 7)
	{
		printf("\nnum = %d\n", num[i]);
		s = ft_itoa(num[i]);
		printf("ft_itoa(%d): '%s'\n", num[i], s);
		j = 0;
		while (s[j])
			j++;
		printf ("Null element on position: %d\n", j);
		free(s);
		i++;
	}
}
char	to_upper_if_even(unsigned int index, char c) {
    if (index % 2 == 0)
	{
        return (ft_toupper(c));
    }
    return (c);
}
void	ft_strmapi_test(void)
{
	int		i;
	char	*s[4] = {"","abcdefg","a1ff2g3h432dfgh", NULL};
	char	*str;
	
	printf("\n---- <ft_strmapi> ----\n\n");
	i = -1;
	while (++i < 4)
	{
		str = ft_strmapi(s[i], to_upper_if_even);
		printf("%p '%s' -> %p '%s'\n", s[i], s[i], str, str);
		free(str);
	}
}
void	to_upper_if_not_even(unsigned int i, char *s)
{
	//printf("i: %d; s[i] = %c\n", i, s[i]);
	if (i % 2 != 0)
		s[i] = ft_toupper(s[i]);
    return;
}

void	ft_striteri_test(void)
{
	int		i;
	char	*s[3] = {"","abcdefg","a1ff2g3h432dfgh"};
	char	str[30];
	
	
	printf("\n---- <ft_striteri> ----\n\n");
	i = -1;
	while (++i < 3)
	{
		ft_strlcpy(str, s[i], 30);
		printf("'%s'\n", str);
		ft_striteri(str, to_upper_if_not_even);
		printf("'%s'\n", str);
	}
}
int	main(void)
{
	/* ft_isalpha_test("1@[`{ahzATZ 	");
	ft_isdigit_test("/059:");	
	ft_isalnum_test("1@[`{ahzATZ \t/059:");
	ft_isascii_test("भा!1~");
	ft_isprint_test();
	ft_strlen_test();
	ft_memset_test();
	ft_bzero_test();
	ft_memcpy_test();
	ft_memmove_test(); 
	ft_strlcat_test(); 
	ft_strlcpy_test(); 
	ft_toupper_test("1aAbBcDxYzZ@[]`{");
	ft_tolower_test("1aAbBcDxYzZ@[]`{");
	ft_strchr_test();
	ft_strrchr_test(); 
	ft_strncmp_test(); 
	ft_memchr_test(); 
	ft_memcmp_test(); 
	ft_strnstr_test();	
	ft_atoi_test();	
	ft_calloc_test();  
	ft_strdup_test();
	ft_substr_test();
	ft_strjoin_test(); 
	ft_strtrim_test(); 
	ft_split_test(); 
	ft_itoa_test(); 
	ft_strmapi_test(); */
	ft_striteri_test();
	
	return (0);
}
