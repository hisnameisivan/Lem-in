/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:07:13 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/25 17:06:59 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(s) + 1;
	while (i < len)
	{
		if (s[i] == (unsigned char)c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
