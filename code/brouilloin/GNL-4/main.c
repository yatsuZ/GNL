/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:58:12 by yzaoui            #+#    #+#             */
/*   Updated: 2023/01/12 19:27:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		fd;
	char	*res;
	int		i;
    char    *fichier_txt;

	fichier_txt = "./fichiertxt/text.txt";
	fd = open(fichier_txt, O_RDONLY);
	i = 1;
	printf("DEBUT de lecture de \"%s\" :\n\n", fichier_txt);
	while (i >= 0)
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