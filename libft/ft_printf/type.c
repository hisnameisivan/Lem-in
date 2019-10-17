/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 19:30:19 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/21 17:13:40 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr_pf(char const *str, int *count)
{
	if (str)
		while (*str)
		{
			write(1, str, 1);
			(*count)++;
			str++;
		}
}

void	ft_type_space(int spaces, int *count)
{
	while (spaces > 0)
	{
		ft_putchar_pf(' ', count);
		spaces--;
	}
}

void	ft_type_nul(int nul, int *count)
{
	while (nul > 0)
	{
		ft_putchar_pf('0', count);
		nul--;
	}
}

void	ft_type_sp_nul(int nul, int *count)
{
	while (nul > 0)
	{
		ft_putchar_pf('0', count);
		nul--;
	}
}
