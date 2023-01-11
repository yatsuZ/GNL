/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:10:19 by yzaoui            #+#    #+#             */
/*   Updated: 2022/12/31 14:04:25 by yzaoui           ###   ########.fr       */
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
	while (cha && cha[i] != '\0')
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
