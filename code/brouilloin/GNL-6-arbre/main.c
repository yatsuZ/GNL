/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:05:20 by yzaoui            #+#    #+#             */
/*   Updated: 2023/02/06 23:41:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//je recomence car je veux que tout soit vert
//0 cree tout fichier important et ramener les fichier txt
//1 crre mon .h
#include "get_next_line.h"
#include <stdio.h>// pour printf
#include <time.h>// pour verifier le temp d'execution de mon code
//2 cree maintenant mon main
//3 cree la onction ge_next_line_mtn

int main()
{
	int		fd;//le fichier
	char	*res;//le return de gnl
	int		i;//le compteur pour ma boucle
	char	*path_fd;//chemin du fichier
	time_t start, end;//2 var de type time pour regarde en cobient de temp sexecute le code
///////////////Debut du chrono
	time(&start);
///////////////initialisation
	i = 0;
	res = NULL;
	path_fd = "fichiertxt/multiple_nlx5.txt";
	fd = open(path_fd, O_RDONLY);//jouvre le fichier
	printf("fd = %d\n", fd);
	printf("DEBUT de lecture de \"%s\" :\n\n", path_fd);
///////////////boucle daffichage
	while (i >= 0)
	{
		res = get_next_line(fd);
		printf("\nligne %d = %s\n", i, res);
		i++;
		if (i > 50 || !res)
			i = -1;
		free(res);
	}
///////////////Fin du code
	close(fd);
	time(&end);
	double temp_execution = difftime(end, start);
	printf("\nTemps d'exécution : %f secondes\n", temp_execution);
	return (0);
}
