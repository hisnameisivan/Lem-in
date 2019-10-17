/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:30:15 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/25 16:01:11 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s_new;

	i = 0;
	s_new = (const char*)s;
	while (i < n)
	{
		if (s_new[i] == (char)c)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
