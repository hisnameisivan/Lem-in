/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 20:54:48 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/25 15:44:12 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_new;
	unsigned char	*src_new;
	size_t			i;

	if (dst == src)
		return (dst);
	i = 0;
	dst_new = (unsigned char*)dst;
	src_new = (unsigned char*)src;
	if (dst_new < src_new)
	{
		while (i < len)
		{
			dst_new[i] = src_new[i];
			i++;
		}
	}
	else
		while (len)
		{
			len--;
			dst_new[len] = src_new[len];
		}
	return (dst_new);
}
