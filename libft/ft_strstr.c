/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:08:24 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/25 17:59:51 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	t = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[t] != '\0')
	{
		j = 0;
		i = t;
		while (s2[j] == s1[i])
		{
			if (s2[j + 1] == '\0')
				return ((char*)s1 + t);
			i++;
			j++;
		}
		t++;
	}
	return (NULL);
}
