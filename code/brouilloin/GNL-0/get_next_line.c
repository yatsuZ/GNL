/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:52:01 by yzaoui            #+#    #+#             */
/*   Updated: 2022/12/27 19:45:04 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//static int BUFFER_SIZE = 1;// a suprimer

static int  find_n(char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

// je fais que read tant qu cest pas /n ou nul ou error une fois 
static char *get_line(int fd, char *ligne)
{
	char        *buf;
    int         nb_read;

    nb_read = BUFFER_SIZE;
    while (nb_read != 0)
    {

	    buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	    nb_read = read(fd, buf, BUFFER_SIZE);
	    if (nb_read < 0 || !buf || (nb_read == 0 && ligne[0] == '\0'))
        {
            free (buf);
            return (NULL);
        }
        buf[BUFFER_SIZE] = '\0';
        ligne = ft_strjoin(ligne, buf);
        if (find_n(buf) >= 0)
        {
            free(buf);
            return (ligne);
        }
        free(buf);
    }
    return (ligne);
}

//je veux ligne retourne le ligne actuelle avec un \n
//et allfd contie
char	*get_next_line(int fd)
{
    static char *allfd[FOPEN_MAX];
    char        *ligne;

    
}