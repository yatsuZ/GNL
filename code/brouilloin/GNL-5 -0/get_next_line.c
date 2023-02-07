/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:26:18 by yzaoui            #+#    #+#             */
/*   Updated: 2023/02/06 19:28:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//0 verifier que le fd et buffer_size sont valide | V
//1 lire tant que ce nest pas la fin et tant que y a pas \n | V
//2 metre le reste de ce quon a lu dans la variable static| X
#include "get_next_line.h"
#include <stdio.h>

char	*ft_strcutendl(char *str, char **after, register int i, register int i_endl)
{
	char	*before;

	before = ft_calloc((i_endl + 2), sizeof(char));
	if (!before)
		return (NULL);
	(*after) = ft_calloc((ft_strlen_or_findendl(str, 0)) - i_endl + 1, \
	sizeof(char));
	if (!(*after))
		return (free(before), NULL);
	while (str[i])
	{
		if (i <= i_endl)
			before[i] = str[i];
		else if (i > i_endl)
			(*after)[i - i_endl - 1] = str[i];
		i++;
	}
	before[i_endl + 1] = '\0';
	(*after)[i - i_endl - 1] = '\0';
	
	return (before);
}

char	*get_line(int fd, char *reste)
{
	char	*all_read;
	char	*buff;//consiste a prendre directement la valeur de read
	int		nbr_read;//le nbr d'octet lu par read
	char	*tmp;//var temporaire
	
	all_read = ft_strjoin(NULL, reste);//rajoute tut le surplus
	
	free(reste);//je free mais je dois dire aque reste est null en de hors
	
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	
	nbr_read = BUFFER_SIZE;
	//cree une opion 2 qui retourne 1 i /n ou 0 si y a pas
	
	while (nbr_read == BUFFER_SIZE && !ft_strlen_or_findendl(buff, 2))
	{
		nbr_read = read(fd, buff, BUFFER_SIZE);
	
		//si <0 alors il y a une erreur de lecture
		//si =0 alors il na rien lu
		if (nbr_read <= 0)
			break;
	
		buff[nbr_read] = '\0';//pour stoper la lecture 
	
		tmp =  ft_strdup(all_read, 1);
		all_read =  ft_strjoin(tmp, buff);
	
		if (!all_read)
			return (free(buff), NULL);
	}
	
	return (free(buff), all_read);
}

char	*get_next_line(int fd)
{
	static char *reste_fd;//tout ce qui est apres le \n
	char		*lecture_buff;//la valeur retour de get_line
	char		*ligne;//ce que je vais return
	int			i_endl;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	if (!reste_fd)
		reste_fd = NULL;
		
	lecture_buff =  get_line(fd, reste_fd);
 	reste_fd = NULL;
	if (!lecture_buff)
		return (NULL);
		
	i_endl = ft_strlen_or_findendl(lecture_buff, 1);
	if (!lecture_buff[i_endl] || !lecture_buff[i_endl + 1])
		return (lecture_buff);
	ligne = ft_strcutendl(lecture_buff, &reste_fd, 0, i_endl);
	return (free(lecture_buff), ligne);

}
