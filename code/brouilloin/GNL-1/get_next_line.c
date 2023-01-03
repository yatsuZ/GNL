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
static void get_a_new_line(int fd, char *ligne, char *str_fd[FOPEN_MAX])
{
	char        *buf;
    char        *tmp;
    int         nb_read;

    nb_read = BUFFER_SIZE;
    buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buf)
    {
        ligne = NULL;
        return;
    }
    while (nb_read != 0 && find_n(buf) < 0)
    {
	    nb_read = read(fd, buf, BUFFER_SIZE);
        buf[BUFFER_SIZE] = '\0';
        printf("%s\n", buf);
	    if (nb_read < 0 || (nb_read == 0 && !str_fd[fd]))
        {
            free (buf);
            return;
        }
        if (str_fd[fd])
        {
            ligne = ft_strdup(str_fd[fd]);
            free(str_fd[fd]);
        }
        tmp = ft_strjoin(ligne, buf);
        if (ligne)
            free (ligne);
        ligne = tmp;
    }
    free(buf);
    return;
}

char	*get_next_line(int fd)
{
    char        *ligne;
    static char *str_fd[FOPEN_MAX];

    if (BUFFER_SIZE < 0 || fd < 0)
        return (NULL);
    ligne = "";
    get_a_new_line(fd, ligne, str_fd);
    if (!ligne)
            return (NULL);
/*     if (!str_fd[fd])
        ligne = "";
    else
        ligne = ft_strdup(allfd[fd]);
    free(allfd[fd]); */
    if (find_n(ligne) < 0)
    {
        get_a_new_line(fd, ligne, str_fd);
        if (!ligne)
            return (NULL);
    }
    if (find_n(ligne) < 0)
        return (ligne);
    str_fd[fd] = ft_substr(ligne, find_n(ligne)+1, ft_strlen(ligne) - find_n(ligne)-1);
    ligne = ft_substr(ligne, 0, find_n(ligne)+1);
    return (ligne);
}