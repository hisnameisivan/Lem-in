/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:10:17 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/25 16:24:34 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *app, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i] != '\0')
		i++;
	while (app[k] != '\0' && k < n)
	{
		dst[i] = app[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dst);
}
