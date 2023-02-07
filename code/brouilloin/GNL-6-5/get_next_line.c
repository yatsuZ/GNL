/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:26:18 by yzaoui            #+#    #+#             */
/*   Updated: 2023/02/07 03:31:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//strutucrer de sorte que quand je recolte la donne la \n est tjr a la fin d'un
//buffer puis faire en sorte que si y a un \n je retourne directement la lecture
//et je le suprime du tableau.
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
	l->len = read(fd, l->content, BUFFER_SIZE);
	if (l->len <= 0)
	{
		free(l->content);
		l->content = NULL;
		return (free(l), NULL);
	}
	else if (l->len != BUFFER_SIZE || ft_strlen_or_findendl(l->content, 2))
	{
		//ici prendre tout ce qu'il a avant et le metre la suite apres
		return (l->content[l->len] = '\0', l);
	}
	l->next = get_all_buff(ft_lstnew(), fd);
	return (l);
}



void	ft_lstclear(t_list **lst)
{
	if (!lst || !(*lst))
		return ;
	free((*lst)->content);
	(*lst)->content = NULL;
	(*lst)->len = 0;
	ft_lstclear(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}

char *get_ligne(t_list **l, char *ligne, int len_ligne)
{
	t_list *tmp;
	
	if ((*l)->next == NULL)
	{

		ligne = ft_strjoin(ligne, (*l)->content, 0);
		tmp = NULL;
		free((*l)->content);
		free((*l));
		(*l) = tmp;
		return (ligne);
	}
	len_ligne += (*l)->len;//si il y a un \n la je coupe //modifier le strjoin
	ligne = ft_strjoin(ligne, (*l)->content, 0);
	tmp = (*l)->next;
	free((*l)->content);
	free((*l));
	(*l) = tmp;
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
	else//faire une condition qui fais que si il y a un \n ne fais pas
		lecture_fd->next = get_all_buff(ft_lstnew(), fd);
	if (lecture_fd == NULL)
		return(NULL);
	ligne = get_ligne(&lecture_fd, NULL, 0);
	return (ligne);
}


//void	ft_lstiter(t_list *lst, void (*f)(char *))
//{
//	if (!lst || !f)
//		return ;
//	f(lst->content);
//	if (!lst->next)
//		return ;
//	ft_lstiter(lst->next, f);
//}
//
//void	printBuff(char * s)
//{
//	printf("BUFF = %s\n", s);
//}
//
//t_list *get_oneBuff(t_list *l, int fd)
//{
//	l->len = read(fd, l->content, BUFFER_SIZE);
//	return (l);
//}
//