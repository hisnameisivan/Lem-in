/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:36:24 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/25 16:46:58 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	k = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size < len_dst + 1)
		return (len_src + size);
	if (size > len_dst + 1)
	{
		while (dst[i] != '\0')
			i++;
		while (src[k] != '\0' && (i + 1 < size))
		{
			dst[i] = src[k];
			k++;
			i++;
		}
		dst[i] = '\0';
	}
	return (len_dst + len_src);
}
