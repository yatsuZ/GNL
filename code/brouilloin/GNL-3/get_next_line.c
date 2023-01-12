/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:05:44 by yzaoui            #+#    #+#             */
/*   Updated: 2023/01/06 19:17:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_endl(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (i >= 0 && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

//printf non len etc
char	*ft_cut_endl(char *l, char *rest, int i, int i_endl)
{
	char	*res;
	int		len;

	if (i_endl == -1 || !l[i_endl + 1])
		return (l);
	len = ft_strlen(l);
	res = ft_calloc((i_endl + 2), sizeof(char));
	if (!res)
		return (free(l), NULL);
	rest = ft_calloc((len - i_endl - 1), sizeof(char));
	if (!rest)
		return (free(res), free(l), NULL);
	while (i < len)
	{
		if (i <= i_endl)
			res[i] = l[i];
		else if (i == i_endl + 1)
			res[i] = '\0';
		if (i >= i_endl + 1)
			rest[i] = l[i];
		i++;
	}
	rest[i] = '\0';
	return (free(l), res);
}

char	*get_line(int fd)
{
	char	*tmp;
	char	*buff;
	int		nbr_read;

	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	tmp = NULL;
	nbr_read = 1;
	while (1)
	{
		nbr_read = read(fd, buff, BUFFER_SIZE);
		if (!buff && !tmp)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		if (!nbr_read)
			break ;
		tmp = ft_strjoin(tmp, buff);
		if (!tmp)
			return (NULL);
		if (find_endl(tmp) != -1)
			return (tmp);
	}
	return (free(buff), tmp);
}

char	*get_next_line(int fd)
{
	static char	*str_fd;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!str_fd)
		line = get_line(fd);
	else
		line = ft_strjoin(str_fd, get_line(fd));
	if (!line)
		return (NULL);
	return (ft_cut_endl(line, str_fd, 0, find_endl(line)));
}
//		line = get_line(fd);//recupere la ligne
//		line = ft_strjoin(str_fd, get_line(fd));//free str_fd et get_line
//		return (ft_cut_endl(line, str_fd));//free line
