/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 21:29:04 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/21 21:38:58 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_ucount_of_digits(unsigned long long n)
{
	int count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

long long			ft_count_of_digits(long long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
		n = (-1) * n;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char				*ft_long_to_ascii(long long n)
{
	char	*res;
	int		i;
	int		is_neg;

	is_neg = 1;
	if (n < 0)
		is_neg = -1;
	i = ft_count_of_digits(n);
	if (!(res = ft_strnew(i)))
		return (NULL);
	res[i] = 0;
	while (i)
	{
		res[i - 1] = is_neg * (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (is_neg == -1)
		res[0] = '-';
	return (res);
}

char				*ft_ulong_to_ascii(unsigned long long n)
{
	char	*res;
	int		i;
	int		is_neg;

	is_neg = 1;
	i = ft_ucount_of_digits(n);
	if (!(res = ft_strnew(i)))
		return (NULL);
	res[i] = 0;
	while (i)
	{
		res[i - 1] = is_neg * (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (is_neg == -1)
		res[0] = '-';
	return (res);
}
