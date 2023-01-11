/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:52:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/01/11 22:19:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strcutendl(char *str, char *after, size_t i)
{
	char	*before;
	size_t	i_endl;

	i_endl = ft_strlen_or_findendl(str, 1);
    if (!str[i_endl])
        return (str);
    before = ft_calloc((i_endl + 2), sizeof(char));
    after = ft_calloc((ft_strlen_or_findendl(str, 0)) - i_endl, sizeof(char));
    while (str[i])
    {
        if (i < i_endl)
            before[i] = str[i];
        if (i == i_endl)
        {
            before[i] = str[i];
            before[i + 1] = '\0';
        }
        if (i > i_endl)
            after[i - i_endl] = str[i];
        i++;
    }
    after[i - i_endl] = '\0';
    return (free(str), before);
}

char    *get_line(int fd, char *reste)
{
    char    *ligne;
    char    *buff;
    
    
    return (ligne);    
}

//je veux ligne retourne le ligne actuelle avec un \n
char	*get_next_line(int fd)
{
    static char *reste_fd;// -> le reste di buffer size apres avoir read un \n
    char        *ligne;// -> la toute la ligne
    
    if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
        return (NULL);
    ligne = get_line(fd, reste_fd);//retourne tout ce que jai pu lire tant que je ne suis pas arrive a la fin et que je nai pas vu de endl
    if (!ligne)
        return (NULL);
    return (ft_strcutendl(ligne, reste_fd, 0));// cut si il y a des charactere apres le premier endl que nous voyons
}