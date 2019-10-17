/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:12:18 by draudrau          #+#    #+#             */
/*   Updated: 2018/12/25 15:26:28 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tab;
	int		i;

	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	if ((tab = (char *)malloc(ft_strlen(s) + 1)) == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		tab[i] = f(s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
