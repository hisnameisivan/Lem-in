/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:08:55 by draudrau          #+#    #+#             */
/*   Updated: 2018/12/25 15:29:58 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (s1 == NULL || s2 == NULL)
	{
		return (0);
	}
	if ((i = ft_strncmp(s1, s2, n)) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
