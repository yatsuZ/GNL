/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:06:34 by yzaoui            #+#    #+#             */
/*   Updated: 2023/01/12 19:36:44 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//si option != 0 il cherchera endl
size_t	ft_strlen_or_findendl(char *s, int option)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (option && s[i] == '\n')
			return (i);
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
		cast[totalsize] = 0;
	return (pt);
}

static char	*ft_strdup(char *s, int option)
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

//je free s2 lors de lallocation
char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*s;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2, 1));
	else if (!s2)
		return (ft_strdup(s1, 1));
	s = ft_calloc(ft_strlen_or_findendl(s1, 0) + \
	ft_strlen_or_findendl(s2, 0) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (i < ft_strlen_or_findendl(s1, 0))
	{
		s[i] = s1[i];
		i++;
	}
	while (j < ft_strlen_or_findendl(s2, 0))
	{
		s[j + i] = s2[j];
		j++;
	}
	return (free(s1), free(s2), s);
}
#include <stdio.h>

int	fusion(char **s1, char *s2)
{
	char	*tmp;
	int		boolean;
	
	boolean = 0;
	if (!s2)
		return (1);
	tmp = ft_strdup((*s1), 1);
	printf("i_endl = %lu et len = %lu\n\n",ft_strlen_or_findendl(s2, 1), ft_strlen_or_findendl(s2, 2));
	if (!tmp)
		return (1);
	if (ft_strlen_or_findendl(s2, 1) == ft_strlen_or_findendl(s2, 2))
		boolean = 1;
	(*s1) = ft_strjoin(tmp, s2);
	return (boolean);
}