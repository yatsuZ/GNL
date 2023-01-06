/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:35:16 by yzaoui            #+#    #+#             */
/*   Updated: 2022/12/31 13:35:18 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int main(void)
{
    int     fd;
    int     i;
    char    *ligne_fd;
    char    *nom_fd = "nl";

    fd = open(nom_fd, O_RDONLY);
    i = 1;
    printf("Je dois lire la premiere line du fichier : %s\n\n", nom_fd);
    
    while (i)
    {
        ligne_fd = get_next_line(fd);
        if (i < 10)
            printf("ligne %i   = |%s", i++, ligne_fd);
        else if (i < 100)
            printf("ligne %i  = |%s", i++, ligne_fd);
        else
            printf("ligne %i = |%s", i++, ligne_fd);
        free(ligne_fd);
        // i = 0;
        if (!ligne_fd)
            i = 0;
    }

    close(fd);
    return (0);
}