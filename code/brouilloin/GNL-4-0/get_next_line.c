/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:52:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/02/06 17:58:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strcutendl(char *str, char **after, size_t i, size_t i_endl)
{
	char	*before;

	before = ft_calloc((i_endl + 2), sizeof(char));
	if (!before)
		return (NULL);
	(*after) = ft_calloc((ft_strlen_or_findendl(str, 0)) - i_endl + 1, \
	sizeof(char));
	if (!(*after))
		return (free(before), NULL);
	while (str[i])
	{
		if (i <= i_endl)
			before[i] = str[i];
		else if (i > i_endl)
			(*after)[i - i_endl - 1] = str[i];
		i++;
	}
	before[i_endl + 1] = '\0';
	(*after)[i - i_endl - 1] = '\0';
	return (before);
}

char	*get_line(int fd, char *reste)
{
	char	*all_read;
	char	*buff;
	char	*tmp;
	int		i_endl;
	int		nbr_read;

	all_read = NULL;
	all_read = ft_strjoin(all_read, reste);
	free(reste);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nbr_read = BUFFER_SIZE;
	i_endl = ft_strlen_or_findendl(buff, 1);
	while (nbr_read == BUFFER_SIZE && !buff[i_endl])
	{
		nbr_read = read(fd, buff, BUFFER_SIZE);
		if (nbr_read <= 0)
			break ;
		tmp = ft_strdup(all_read, 1);
		all_read = ft_strjoin(tmp, buff);
		if (!all_read)
			return (free(buff), NULL);
		i_endl = ft_strlen_or_findendl(buff, 1);
		buff[nbr_read] = '\0';
	}
	return (free(buff), all_read);
}

char	*get_next_line(int fd)
{
	static char	*reste_fd;
	char		*lecture_buffer;
	char		*ligne;
	size_t		i_endl;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	if (!reste_fd)
		reste_fd = NULL;
		
	lecture_buffer = get_line(fd, reste_fd);
	reste_fd = NULL;
	if (!lecture_buffer)
		return (NULL);
		
	i_endl = ft_strlen_or_findendl(lecture_buffer, 1);
	if (!lecture_buffer[i_endl] || !lecture_buffer[i_endl + 1])
		return (lecture_buffer);
	ligne = ft_strcutendl(lecture_buffer, &reste_fd, 0, i_endl);
	return (free(lecture_buffer), ligne);
}
