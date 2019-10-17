/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:08:41 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/25 18:13:39 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	t;

	t = 0;
	i = 0;
	if (s2[i] == '\0' && n)
		return ((char*)s1);
	if (n == 0)
		return (NULL);
	while (t < n && s1[t] != '\0')
	{
		j = 0;
		i = t;
		while (s1[i] == s2[j] && i + 1 <= n)
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
