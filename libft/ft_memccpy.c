/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:44:28 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/25 15:00:33 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	new_c;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	new_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == new_c)
			return (dst1 + i + 1);
		i++;
	}
	return (NULL);
}
