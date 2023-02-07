/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:06:34 by yzaoui            #+#    #+#             */
/*   Updated: 2023/02/06 22:49:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen_or_findendl(char *s, int option)
{
	register int	i;
	char			*s_ptr;

	if (!s)
		return (0);
	s_ptr = s;
	i = 0;
	while (*s_ptr)
	{
		if (*s_ptr == '\n')
		{
			if (option == 1)
				return (i);
			else if (option == 2)
				return (1);
			else if (option == 3)
			{
				s_ptr++;
				return (*s_ptr == '\0');
			}
		}
		s_ptr++;
		i++;
	}
	if (option == 2)
		return (0);
	else if (option == 3)
		return (1);
	return (i);
}

void	*ft_calloc(int nmemb, int size)
{
	void			*pt;
	int				totalsize;
	unsigned char	*cast;

	if (!nmemb && !size)
		return (NULL);
	else if (!nmemb || !size)
		return (malloc(0));
	totalsize = size * nmemb;
	if (totalsize / size != nmemb)
		return (NULL);
	pt = malloc((size_t)totalsize);
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
	char	*ptr_ptr;
	char	*s_ptr;

	if (!s)
		return (NULL);
	ptr = ft_calloc((ft_strlen_or_findendl(s, 0) + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ptr_ptr = ptr;
	s_ptr = s;
	while (*s_ptr)
		*(ptr_ptr++) = *(s_ptr++);
	if (option)
		return (free(s), ptr);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2, int len_total)
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
		
	s = ft_calloc(len_total + 1, sizeof(char));
	
	s_ptr = s;
	s1_ptr = s1;
	s2_ptr = s2;
	
	while (*s1_ptr)
		*(s_ptr++) = *(s1_ptr++);
	while (*s2_ptr)
		*(s_ptr++) = *(s2_ptr++);
	return (free(s1), s);
}


char	*ft_memcpy(char *dest, char *src, int n)
{
    register int    i;

    i = 0;
    if (!dest || !src)
        return (dest);
    while (i < n)
    {
        if ((n - i) >= 8)
        {
            ((long long *)dest)[i / 8] = ((long long *)src)[i / 8];
            i += 7;
        }
        else if ((n - i) >= 4)
        {
            ((int *)dest)[i / 4] = ((int *)src)[i / 4];
            i += 3;
        }
        else
            dest[i] = src[i];
        i++;
    }
    return (dest);
}
