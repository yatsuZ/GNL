/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2022/12/31 14:46:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*cs2;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	cs2 = (char *) s2;
	i = 0;
	j = 0;
	s = ft_calloc(ft_strlen(s1) + ft_strlen(cs2) + 1, sizeof(char));
	while (i < ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(cs2))
	{
		s[j + i] = cs2[j];
		j++;
	}
	return (s);
}

static int	find_endl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// I only read as long as it is not "/n" or null 
//or error or that nbr_read is different from 0
static char	*get_line(int fd, char *ligne)
{
	int		nbr_read;
	char	*buff;
	int		bool;
	char	*tmp;

	nbr_read = 1;
	tmp = NULL;
	bool = TRUE;
	buff = calloc(BUFFER_SIZE + 1, sizeof(char));
	while (nbr_read != 0 && bool)
	{
		nbr_read = read(fd, buff, BUFFER_SIZE);
		
		if (!buff)
			return (free(ligne), NULL);
		
		buff[BUFFER_SIZE] = '\0';
		
		if (nbr_read < 0 || (!nbr_read && !ligne[0]))
			return (free(ligne), free(buff), NULL);

		if (nbr_read == 0)
			break;
		
		tmp = ft_strjoin(ligne, buff);
		free(ligne);
		
		if (!tmp)
			return (free(buff), NULL);
		
		ligne = ft_strdup(tmp);
		free(tmp);
		if (!ligne)
			return (NULL);
		if (find_endl(buff) != -1)
			bool = FALSE;
	}
	free(buff);
	return (ligne);
}

char	*get_next_line(int fd)
{
	static char	*str_fd[FOPEN_MAX];
	char		*ligne;
	// char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!str_fd[fd])
	{
		ligne = malloc(1);
		ligne[0] = '\0';
	}
	else
	{
		ligne = ft_strdup(str_fd[fd]);
		free (str_fd[fd]);
		if (!ligne)
			return (NULL);
	}
	ligne = get_line(fd, ligne);
	if (!ligne)
		return (NULL);
	if (find_endl(ligne) == -1)
		return (ligne);
	str_fd[fd] = ft_substr(ligne, find_endl(ligne)+1, \
	ft_strlen(ligne) - find_endl(ligne)-1);
	ligne = ft_substr(ligne, 0, find_endl(ligne)+1);
	return (ligne);
}
