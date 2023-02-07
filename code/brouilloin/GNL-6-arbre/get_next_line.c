/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:26:18 by yzaoui            #+#    #+#             */
/*   Updated: 2023/02/07 01:05:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//0 verifier que le fd et buffer_size sont valide | V
//1 cree la struc t_list | V
//2 tant que je ne suis pas arriver a la fin et que y a pas de \n j'ajoute a lecture fd | V
//3 il faux mtn je concatene
#include "get_next_line.h"
#include <stdio.h>

t_list	*ft_lstnew()
{
	t_list	*tmp;

	tmp = ft_calloc(1, sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = ft_calloc(BUFFER_SIZE + 1, sizeof(char ));
	tmp->len = 0;
	tmp->next = NULL;
	return (tmp);
}

t_list *get_all_buff(t_list *l, int fd)
{
	//ajouter la str
	l->len = read(fd, l->content, BUFFER_SIZE);
	//Fin
	if (l->len <= 0)
	{
		//printf("read error ou null fin y a plus rien | l->len = %d\n", l->len);
		free(l->content);
		l->content = NULL;
		return (free(l), NULL);
	}
	else if (l->len != BUFFER_SIZE || ft_strlen_or_findendl(l->content, 2))
	{
		//printf("il y a un \\n ou je lis la fin | Buffer_size= %d rt nbr_read = %d| \n", BUFFER_SIZE, l->len);
		return (l->content[l->len] = '\0', l);
	}
	//sinon
	//printf("sa contvinue \n");
	l->next = get_all_buff(ft_lstnew(), fd);
	//printf("FIN \n");
	return (l);
}

void	ft_lstiter(t_list *lst, void (*f)(char *))
{
	if (!lst || !f)
	{
		//printf("actuelle= NUll");
		return ;
	}
	f(lst->content);
	if (!lst->next)
	{
		//printf("NEXT= NUll");
		return ;
	}
	ft_lstiter(lst->next, f);
}

void	printBuff(char * s)
{
	printf("BUFF = %s\n", s);
}

t_list *get_oneBuff(t_list *l, int fd)
{
	//ajouter la str
	l->len = read(fd, l->content, BUFFER_SIZE);
	//Fin
	return (l);
}


void	ft_lstclear(t_list **lst)
{
	if (!lst || !(*lst))
		return ;
	//surpimer les info
	free((*lst)->content);
	(*lst)->content = NULL;
	(*lst)->len = 0;
	//
	ft_lstclear(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}

char *surplus(char *base, int debut, int len)
{
	char	*str;
	int		i;
	
	str = ft_calloc((len - debut) + 1, sizeof(char));
	i = 0;
	while (debut < len)
		str[i++] = base[debut++]; 
	return (str);
}

//faire un aller pour recupere le nombre total de char
//arriver au bout je fait un calloc 
//puis sur le retour ajouter a la string et clear
char *get_ligne(t_list **l, char *ligne, int len_ligne)
{
	t_list *tmp;
	int		i_endl;
	int		dif;
	
	if ((*l)->next == NULL)
	{
		len_ligne += (*l)->len;
		i_endl = ft_strlen_or_findendl((*l)->content, 1);
		dif = 0;
		if ((*l)->content[i_endl] == '\n')
		{
			dif = (*l)->len - 1 - i_endl;
			(*l)->next = ft_lstnew();
			(*l)->next->content = surplus((*l)->content, i_endl, (*l)->len);
		}
		ligne = ft_strjoin(ligne, (*l)->content, len_ligne - (dif));
		return (ligne);
	}
	//je concatene
	len_ligne += (*l)->len;
	ligne = ft_strjoin(ligne, (*l)->content, len_ligne);
	//printf("ligne = %s\n\n", ligne);
	//je doit suprimer et dire que la suivante devient la tete actuelle
	tmp = (*l)->next;
	free((*l)->content);
	free((*l));
	(*l) = tmp;
	///
	return (get_ligne(l, ligne, len_ligne));
}

char *get_next_line(int fd)
{
	static t_list	*lecture_fd;
	char			*ligne;
	t_list			*tmp;
	
	tmp = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	if (lecture_fd == NULL)
		lecture_fd = get_all_buff(ft_lstnew(), fd);
	else
		lecture_fd->next = get_all_buff(ft_lstnew(), fd);
	//printf("ajout du read buff\n");
	if (lecture_fd == NULL)
		return(NULL);
	//printf("affichage des buffs\n");
	//ft_lstiter(lecture_fd, printBuff);
	//netoyer pas de leak chez mi monsieur
	ligne = get_ligne(&lecture_fd, NULL, 0);
	// if (lecture_fd != NULL && lecture_fd->next != NULL)
	// {
	// 	tmp = lecture_fd->next;
	// 	free(lecture_fd->content);
	// 	free(lecture_fd);
	// 	lecture_fd = tmp;
	// }
	return (ligne);
}
