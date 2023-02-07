/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:26:18 by yzaoui            #+#    #+#             */
/*   Updated: 2023/02/07 18:35:51 by yzaoui           ###   ########.fr       */
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

t_list	*surplus(t_list *l, register int i)//je dois relouer de la memoir au content et ajouter le reste 
{
	char	*before;
	t_list	*after;
	
	if (l->have_endl + 1 == l->len)//si \n est le dernier charactere rien a changer
		return (l);

	before = ft_calloc(l->have_endl + 2, sizeof(char));//before = toute la chaine charactere avant le \n
	after = ft_lstnew();//after = une liste elle contiendra tout ce quil y a apres le \n
	
	//jecris dans before et after 
	while (l->content[i])
	{
		if (i<= l->have_endl)
			before[i] = l->content[i];
		else if  (i > l->have_endl)
			after->content[i - l->have_endl - 1] = l->content[i];
		i++;
	}
	before[l->have_endl + 1] = '\0';
	after->len = i - l->have_endl - 1;
	after->have_endl = ft_strlen_or_findendl(after->content, 1);
	//printf("BEFORE = %s.\n", before);
	//printf("AFTER = %s.\n", after->content);
	free(after->content);
	free(after);
	free(before);
	return (l);
}

t_list *get_all_buff(t_list *l, int fd)//refaire
{
	l->len = read(fd, l->content, BUFFER_SIZE);
	if (l->len <= 0)
	{
		free(l->content);
		l->content = NULL;
		return (free(l), NULL);
	}
	else if (l->len != BUFFER_SIZE)
		return (l->content[l->len] = '\0',l->have_endl = ft_strlen_or_findendl(l->content, 1), l);
	else if (ft_strlen_or_findendl(l->content, 2))
		//ici prendre tout ce qu'il a avant et le metre la suite apres
		return (l->content[l->len] = '\0', l->have_endl = ft_strlen_or_findendl(l->content, 1), surplus(l, 0));
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
		ligne = ft_strjoin(ligne, (*l)->content, len_ligne);
		tmp = (*l)->next;
		free((*l)->content);
		free((*l));
		(*l) = tmp;
		return (ligne);
	}
	len_ligne += (*l)->len;
	ligne = ft_strjoin(ligne, (*l)->content, len_ligne);
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
	// else if (!ft_strlen_or_findendl(lecture_fd->content,2))//PEUT ETRE INUTILE// faire le cas que le reste que jai nest pas de \n
	// 	lecture_fd->next = get_all_buff(ft_lstnew(), fd);
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
//	//printf("BUFF = %s\n", s);
//}
//
//t_list *get_oneBuff(t_list *l, int fd)
//{
//	l->len = read(fd, l->content, BUFFER_SIZE);
//	return (l);
//}
//