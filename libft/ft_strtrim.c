/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 20:03:02 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/20 17:07:39 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_null_s(void)
{
	char *null_s;

	if ((null_s = (char*)malloc(1)) == NULL)
		return (NULL);
	else
		null_s[0] = '\0';
	return (null_s);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	size_t	w;
	char	*tab;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (*s == '\0' || i == ft_strlen(s))
		return (ft_null_s());
	w = 0;
	k = ft_strlen(s) - 1;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	if ((tab = (char*)malloc(k - i + 2)) == NULL)
		return (NULL);
	while (k >= i + w)
	{
		tab[w] = s[i + w];
		w++;
	}
	tab[w] = '\0';
	return (tab);
}
