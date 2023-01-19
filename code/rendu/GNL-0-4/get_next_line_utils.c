/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:06:34 by yzaoui            #+#    #+#             */
/*   Updated: 2023/01/19 14:25:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_or_findendl(char *s, int option)
{
	size_t	i;
	char	*s_ptr;

	if (!s)
		return (0);
	s_ptr = s;
	i = 0;
	while (*s_ptr)
	{
		if (option && *s_ptr == '\n')
			return (i);
		s_ptr++;
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*pt;
	size_t			totalsize;
	unsigned char	*cast;

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
	cast = (unsigned char *)pt;
	while (totalsize--)
		*(cast++) = 0;
	return (pt);
}

char	*ft_strdup(char *s, int option)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	ptr = ft_calloc((ft_strlen_or_findendl(s, 0) + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	if (option)
		return (free(s), ptr);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*s;
	char		*s_ptr;
	char		*s1_ptr;
	char		*s2_ptr;

	if (!s1 && !s2)
		return (NULL);
	else if (!s2)
		return (s1);
	else if (!s1)
		return (ft_strdup(s2, 0));
	s = ft_calloc(ft_strlen_or_findendl(s1, 0) + \
	ft_strlen_or_findendl(s2, 0) + 1, sizeof(char));
	s_ptr = s;
	s1_ptr = s1;
	s2_ptr = s2;
	while (*s1_ptr)
	{
		*s_ptr = *s1_ptr;
		s_ptr++;
		s1_ptr++;
	}
	while (*s2_ptr)
	{
		*s_ptr = *s2_ptr;
		s_ptr++;
		s2_ptr++;
	}
	return (free(s1), s);
}

