/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:43:29 by draudrau          #+#    #+#             */
/*   Updated: 2019/01/15 18:50:55 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parts(char const *s, char c)
{
	int		i;
	int		count;
	_Bool	fl;

	i = 0;
	fl = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			fl = 0;
		else if (!fl)
		{
			count++;
			fl = 1;
		}
		i++;
	}
	return (count);
}

static int	ft_l(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		return (len);
	}
	return (0);
}

static void	ft_free(char ***tab, int k)
{
	while (k--)
	{
		free((*tab)[k]);
		(*tab)[k] = NULL;
	}
	free(*tab);
	*tab = NULL;
}

static char	**ft_spl(char **t, char const *s, char c)
{
	int k;
	int n;

	k = 0;
	n = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			if ((t[k] = (char*)malloc(sizeof(char) * (ft_l(s, c) + 1))) == NULL)
			{
				ft_free(&t, k);
				return (NULL);
			}
			while (*s != c && *s != '\0')
				t[k][n++] = (char)*s++;
			t[k][n] = '\0';
			n = 0;
			k++;
		}
	}
	t[k] = NULL;
	return (t);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;

	if (s == NULL)
		return (NULL);
	if ((t = (char**)malloc(sizeof(char*) * (ft_parts(s, c) + 1))) == NULL)
		return (NULL);
	return (ft_spl(t, s, c));
}
