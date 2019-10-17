/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:20:45 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/15 15:52:42 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;
	t_list *tab;

	if (!alst || !del)
		return ;
	tab = *alst;
	while (tab)
	{
		new = tab->next;
		del(tab->content, tab->content_size);
		free(tab);
		tab = new;
	}
	*alst = NULL;
}
