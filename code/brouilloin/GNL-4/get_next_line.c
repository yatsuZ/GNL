/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:52:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/01/12 19:37:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strcutendl(char *str, char **after, size_t i, size_t i_endl)//valide pas derreur de memoir
{
	char	*before;

    before = ft_calloc((i_endl + 2), sizeof(char));
    if (!before)
        return (NULL);
    (*after) = ft_calloc((ft_strlen_or_findendl(str, 0)) - i_endl + 1, sizeof(char));
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



char    *get_line(int fd, char *reste)
{
    char    *all_read;
    char    *buff;
    int     nbr_read;

    all_read = NULL;
    fusion(&all_read, reste);
    buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    nbr_read = BUFFER_SIZE;
    while (nbr_read == BUFFER_SIZE)
    {
        nbr_read = read(fd, buff, BUFFER_SIZE);
        if (!all_read)
        if (fusion(&all_read, buff))
            break;
    }
    return (all_read);    
}

//je veux ligne retourne le ligne actuelle avec un \n
char	*get_next_line(int fd)
{
    static char *reste_fd;// -> le reste di buffer size apres avoir read un \n
    char        *lecture_buffer;// tout ce que le buffer a lu
    char        *ligne;//-> la ligne que je doit retourner
    size_t      i_endl;// index du permier \n ou sinon la longuer de la string
    
    if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
        return (NULL);
    lecture_buffer = get_line(fd, reste_fd);//retourne tout ce que jai pu lire tant que je ne suis pas arrive a la fin et que je nai pas vu de endl
	if (!lecture_buffer)
		return (NULL);
	i_endl = ft_strlen_or_findendl(lecture_buffer, 1);
    if (!lecture_buffer[i_endl])
    {
        if (reste_fd)
            free(reste_fd);
        reste_fd = NULL;
        return (lecture_buffer);
    }
    ligne = ft_strcutendl(lecture_buffer, &reste_fd, 0, i_endl);// cut si il y a des charactere apres le premier endl que nous voyons
    return (free(lecture_buffer), ligne);
}
