/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:14:07 by draudrau          #+#    #+#             */
/*   Updated: 2018/12/22 15:40:29 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	if ((tab = malloc(size)) == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
