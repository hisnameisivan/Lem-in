/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:37:29 by draudrau          #+#    #+#             */
/*   Updated: 2019/02/02 16:00:57 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		k;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	k = 0;
	if ((tab = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[k] != 0)
	{
		tab[i] = s2[k];
		i++;
		k++;
	}
	tab[i] = '\0';
	return (tab);
}
