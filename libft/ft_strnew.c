/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:53:42 by draudrau          #+#    #+#             */
/*   Updated: 2019/02/02 17:51:21 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	if (size + 1 == 0)
		return (NULL);
	if ((tab = (char*)malloc(size + 1)) == NULL)
		return (NULL);
	else
		ft_bzero(tab, size + 1);
	return (tab);
}
