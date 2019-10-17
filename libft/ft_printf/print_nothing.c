/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nothing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 19:52:00 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/19 21:39:28 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_nothing_12(t_pf *pf, int sit, int *count)
{
	if (sit == 1)
	{
		ft_putchar_pf('+', count);
		ft_type_space(pf->wid - 1, count);
	}
	else if (sit == 2)
	{
		if (pf->space == 1 && !pf->plus)
		{
			ft_putchar_pf(' ', count);
			pf->wid--;
		}
		ft_type_space(pf->wid, count);
	}
	return (1);
}

int		ft_print_nothing_34(t_pf *pf, int sit, int *count)
{
	if (sit == 3)
	{
		if (pf->plus == 1)
			ft_putchar_pf('+', count);
		else if (pf->plus == 0 && pf->space == 1)
			ft_putchar_pf(' ', count);
		ft_putchar_pf('0', count);
		ft_type_space(pf->wid - 2, count);
	}
	else if (sit == 4)
	{
		pf->wid = pf->wid - ((pf->prec - 1 < 0) ? 0 : pf->prec - 1);
		if (pf->prec)
			ft_type_nul(pf->prec - 1, count);
		ft_putchar_pf('0', count);
		ft_type_space(pf->wid - 1, count);
	}
	return (1);
}

int		ft_print_nothing_56(t_pf *pf, int sit, int *count)
{
	if (sit == 5)
	{
		pf->wid = pf->wid - ((pf->prec - 1 < 0) ? 0 : pf->prec - 1);
		(pf->dot == 0 && pf->nul == 1) ? ft_type_sp_nul(pf->wid - 1, count) :
		ft_type_space(pf->wid - 1, count);
		if (pf->prec)
			ft_type_nul(pf->prec - 1, count);
		ft_putchar_pf('0', count);
	}
	else if (sit == 6)
	{
		ft_putchar_pf('+', count);
		ft_type_sp_nul(pf->wid - 2, count);
		ft_putchar_pf('0', count);
	}
	return (1);
}

int		ft_print_nothing_78(t_pf *pf, int sit, int *count)
{
	if (sit == 7)
	{
		ft_type_space(pf->wid - 2, count);
		ft_putchar_pf('+', count);
		ft_putchar_pf('0', count);
	}
	else if (sit == 8)
	{
		ft_type_space(pf->wid - 1, count);
		ft_putchar_pf('+', count);
	}
	return (1);
}
