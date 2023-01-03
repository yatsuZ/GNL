/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:58:12 by yzaoui            #+#    #+#             */
/*   Updated: 2022/12/27 19:47:02 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*res;
	int		i;

	fd = open("./text.txt", O_RDONLY);
	i = 1;
	while (i >= 0)//je veux juste affiche un fichier vide
	{
		res = get_next_line(fd);
		printf("ligne %d = %s\n", i, res);
		i++;
		if (i > 50 || !res)
			i = -1;
	}
	close(fd);
	return (0);
}

    if (!allfd[fd])
        ligne = "";
    else
    {
        ligne = ft_strdup(allfd[fd]);
    }
    free(allfd[fd]);
    if (find_n(ligne) < 0)
    {
        ligne = get_line(fd, ligne);
        if (!ligne)
            return (NULL);
    }
    if (find_n(ligne) < 0)
    {
        ligne = get_line(fd, ligne);
        if (!ligne)
            return (NULL);
    }
    if (find_n(ligne) < 0)
        return (ligne);
    allfd[fd] = ft_substr(ligne, find_n(ligne)+1, ft_strlen(ligne) - find_n(ligne)-1);
    ligne = ft_substr(ligne, 0, find_n(ligne)+1);
    return (ligne);