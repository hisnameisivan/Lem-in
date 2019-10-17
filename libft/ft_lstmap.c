/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:00:58 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/20 15:57:30 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	while ((*list)->next)
	{
		tmp = (*list)->next;
		free(*list);
		(*list) = tmp;
	}
	*list = NULL;
	return ;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new;

	if (!lst || !(*f))
		return (NULL);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	start = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = (t_list*)malloc(sizeof(t_list))) ||
		!(new->next = f(lst)))
		{
			ft_free(&start);
			return (NULL);
		}
		new = new->next;
	}
	new->next = NULL;
	return (start);
}
