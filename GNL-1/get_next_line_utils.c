/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:52:16 by yzaoui            #+#    #+#             */
/*   Updated: 2022/12/27 19:48:26 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*cast;

	if (!s)
		return (NULL);
	cast = (unsigned char *)s;
	while (n--)
		cast[n] = 0;
	return (s);
}

size_t	ft_strlen(const char *cha)
{
	size_t	i;

	i = 0;
	while (cha[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i++;

	return (ft_strlen((char *)src));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;
	size_t	totalsize;

	if (!nmemb && !size)
		return (NULL);
	else if (!nmemb || !size)
		return (malloc(0));
	totalsize = size * nmemb;
	if (totalsize / size != nmemb)
		return (NULL);
	pt = malloc(totalsize);
	if (!pt)
		return (NULL);
	ft_bzero(pt, totalsize);
	return (pt);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *) s;
	len = ft_strlen(str) + 1;
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str);
	return (ptr);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*cs1;
	char	*cs2;
	char	*s;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup((char const *) s1));
	cs1 = (char *) s1;
	cs2 = (char *) s2;
	i = 0;
	j = 0;
	s = ft_calloc(ft_strlen(cs1) + ft_strlen(cs2) + 1, sizeof(char));
	while (i < ft_strlen(cs1))
	{
		s[i] = cs1[i];
		i++;
	}
	while (j < ft_strlen(cs2))
	{
		s[j + i] = cs2[j];
		j++;
	}
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lon;
	char	*news;
	size_t	space;

	if (!s)
		return (NULL);
	lon = ft_strlen((char *) s);
	if (start > lon)
		return (ft_strdup(""));
	space = lon - start ;
	if (space > len)
		space = len;
	news = ft_calloc(space + 1, sizeof(char));
	i = 0;
	while (s[i + start] && i < len)
	{
		news[i] = s[i + start];
		i++;
	}
	if (news[i])
		news[i] = '\0';
	return (news);
}