/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:06:34 by yzaoui            #+#    #+#             */
/*   Updated: 2023/01/11 19:49:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
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

	ptr = ft_calloc((ft_strlen(s) + 1), sizeof(char));
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
	int		i;
	int		j;

	char	*s;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	i = -1;
	j = -1;
	s = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	while (++i < ft_strlen(s1))
		s[i] = s1[i];
	while (++j < ft_strlen(s2))
		s[j + i] = s2[j];
	return (free(s1), free(s2), s);
}
