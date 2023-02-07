/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:05:51 by psage             #+#    #+#             */
/*   Updated: 2022/11/17 20:26:15 by psage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

char *get_next_line(int fd);

int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		printf("%s\n", get_next_line(0));
		return (0);
	}
	int	fd = open(argv[1], O_RDONLY);
	char *s;
	do {
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
	} while(s);
}
