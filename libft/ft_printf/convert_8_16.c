/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_8_16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 21:44:54 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/21 21:37:39 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fill_ost(int *ost, unsigned long long num, unsigned long long base)
{
	int		i;

	i = 0;
	while (num > base - 1)
	{
		ost[i] = num % base;
		num = num / base;
		i++;
	}
	ost[i] = num;
	return (i);
}

char	*ft_convert_v_8(unsigned long long num)
{
	int					i;
	int					ost[23];
	char				*oct_num;
	char				*oct_temp;

	oct_num = NULL;
	i = ft_fill_ost(ost, num, 8);
	if (!(oct_num = ft_strnew(i + 1)))
		return (NULL);
	oct_temp = oct_num;
	while (i >= 0)
	{
		*oct_num = (char)ost[i] + '0';
		i--;
		oct_num++;
	}
	return (oct_temp);
}

char	*ft_convert_v_16(unsigned long long num, t_pf *pf)
{
	int					i;
	int					ost[23];
	char				*hex_num;
	char				*hex_temp;

	i = 0;
	hex_num = NULL;
	i = ft_fill_ost(ost, num, 16);
	if (!(hex_num = ft_strnew(i + 1)))
		return (NULL);
	hex_temp = hex_num;
	while (i >= 0)
	{
		if (ost[i] < 10)
			*hex_num = (char)ost[i] + '0';
		else
			*hex_num = (char)ost[i] - 10 + ((pf->spec == 'X') ? 'A' : 'a');
		i--;
		hex_num++;
	}
	return (hex_temp);
}
