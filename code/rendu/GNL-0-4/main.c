/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:58:12 by yzaoui            #+#    #+#             */
/*   Updated: 2023/01/19 13:47:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

int	main(void)
{
	int		fd;
	char	*res;
	int		i;
    char    *fichier_txt;
	time_t start, end;
	time(&start);
//////////////////// code à chronométrer
	fichier_txt = "./fichiertxt/big_line.txt";
	fd = open(fichier_txt, O_RDONLY);
	i = 1;
	printf("fd = %d\n", fd);
	printf("DEBUT de lecture de \"%s\" :\n\n", fichier_txt);
	while (i >= 0)
	{
		res = get_next_line(fd);
		printf("\nligne %d = %s\n", i, res);
		i++;
		if (i > 50 || !res)
			i = -1;
		free(res);
	}
	close(fd);
	time(&end);
/////////////////////
	double elapsed_time = difftime(end, start);
	printf("\nTemps d'exécution : %f secondes\n", elapsed_time);
	return (0);
}