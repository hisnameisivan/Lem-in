/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:48:39 by draudrau          #+#    #+#             */
/*   Updated: 2018/12/24 15:13:26 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*s1_new;
	unsigned const char	*s2_new;

	if (n == 0)
		return (0);
	i = 0;
	s1_new = s1;
	s2_new = s2;
	while (i < n)
	{
		if (s1_new[i] != s2_new[i])
		{
			return (s1_new[i] - s2_new[i]);
		}
		i++;
	}
	return (0);
}
