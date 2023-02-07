/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:26:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/02/06 22:51:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
//si le h n'est defini alors vici sa definition du header 
//pk la syntax est en majuscule?
# define GET_NEXT_LINE_H
//la je defini le header
# include <unistd.h>
//pour les fct read et close
# include <stdlib.h>
//pour malloc free
# include <fcntl.h>
//pour open
# include <limits.h>
//pour FOPEN_MAX pour trouver le fd max en fonction de l'infra
# ifndef BUFFER_SIZE
//si buffer_size n'est pas defini alors
#  define BUFFER_SIZE 10//il est egal a 10
# endif//cest si lors de la compilation j'oublie de dire buffer size

typedef struct s_list
{
	char			*content;
    int             len;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strdup(char *s, int option);
char	*ft_strjoin(char *s1, char *s2, int len_total);
int		ft_strlen_or_findendl(char *s, int option);
void	*ft_calloc(int nmemb, int size);
char	*ft_memcpy(char *dest, char *src, int n);

#endif
