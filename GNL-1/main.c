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

	fd = open("text.txt", O_RDONLY);
	i = 1;
	// printf("FD = %d\n", fd);
//	printf("test GNL de random.txt = DEBUT|\n%s\n|FIN.\n", get_next_line(fd));//la jobtien les buffersize premier caractere mtn je veux juste recuperer la premiere ligne
//	printf("test GNL de random.txt ligne 0 = %s\n|FIN", get_next_line(fd));
	while (i >= 0)
	{
		res = get_next_line(fd);
		printf("ligne %d = %s\n", i, res);
		i++;
		if (i > 50 || !res)
			i = -1;
	}
	close(fd);
	// int	fd2;

	// i = 0;
	// fd = open("text.txt", O_RDONLY);
	// fd2 = open("random.txt", O_RDONLY);

	// res = get_next_line(fd);
	// printf("F1 - ligne %d = %s\n", i, res);
	// res = get_next_line(fd2);
	// printf("F2 - ligne %d = %s\n", i++, res);

	// res = get_next_line(fd);
	// printf("F1 - ligne %d = %s\n", i, res);
	// res = get_next_line(fd2);
	// printf("F2 - ligne %d = %s\n", i++, res);

	// res = get_next_line(fd);
	// printf("F1 - ligne %d = %s\n", i, res);
	// res = get_next_line(fd2);
	// printf("F2 - ligne %d = %s\n", i++, res);

	// res = get_next_line(fd);
	// printf("F1 - ligne %d = %s\n", i, res);
	// res = get_next_line(fd2);
	// printf("F2 - ligne %d = %s\n", i++, res);

	// res = get_next_line(fd);
	// printf("F1 - ligne %d = %s\n", i, res);
	// res = get_next_line(fd2);
	// printf("F2 - ligne %d = %s\n", i++, res);

	// res = get_next_line(fd);
	// printf("F1 - ligne %d = %s\n", i, res);
	// res = get_next_line(fd2);
	// printf("F2 - ligne %d = %s\n", i++, res);

	// res = get_next_line(fd);
	// printf("F1 - ligne %d = %s\n", i, res);
	// res = get_next_line(fd2);
	// printf("F2 - ligne %d = %s\n", i++, res);

	// close(fd);
	// close(fd2);
	return (0);
}
