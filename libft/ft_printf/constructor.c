/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 19:39:22 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/19 21:38:30 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_sit_1(t_pf *pf, char *num, int *count)
{
	if (pf->znak == -1)
		ft_putchar_pf('-', count);
	else if (pf->znak == 1 && pf->plus)
		ft_putchar_pf('+', count);
	ft_type_nul(pf->prec, count);
	ft_putstr_pf(num, count);
	ft_type_space(pf->wid, count);
}

void	ft_print_sit_2(t_pf *pf, char *num, int *count)
{
	if (pf->znak == 1 && pf->space)
	{
		ft_putchar_pf(' ', count);
		pf->wid--;
	}
	else if (pf->znak == 0 && pf->spec != 'u' && pf->resh)
	{
		ft_putchar_pf('0', count);
		if (pf->spec != 'o')
			ft_putchar_pf(pf->spec, count);
	}
	ft_type_nul(pf->prec, count);
	ft_putstr_pf(num, count);
	ft_type_space(pf->wid, count);
}

void	ft_print_sit_4(t_pf *pf, char *num, int *count)
{
	if (((pf->spec == 'f' && pf->nul == 0)) || (pf->dot == 1 &&
	(pf->spec == 'd' || pf->spec == 'i')) || (pf->dot == 0 && pf->nul == 0))
		ft_type_space(pf->wid, count);
	if (pf->znak == -1)
		ft_putchar_pf('-', count);
	else if (pf->znak == 1 && pf->plus)
		ft_putchar_pf('+', count);
	if ((pf->dot == 0 && pf->nul == 1) || (pf->spec == 'f' && pf->nul == 1))
		ft_type_sp_nul(pf->wid, count);
	ft_type_nul(pf->prec, count);
	ft_putstr_pf(num, count);
}

void	ft_print_sit_6(t_pf *pf, char *num, int *count)
{
	if (pf->znak == 1 && pf->space)
	{
		ft_putchar_pf(' ', count);
		pf->wid--;
	}
	if (((pf->spec == 'f' && pf->nul == 0)) || (pf->dot == 1
	&& (pf->spec != 'f')) || (pf->dot == 0 && pf->nul == 0))
		ft_type_space(pf->wid, count);
	if (pf->znak == 0 && pf->spec != 'u' && pf->resh)
	{
		if (pf->spec == 'o')
			ft_putchar_pf('0', count);
		else
		{
			ft_putchar_pf('0', count);
			ft_putchar_pf(pf->spec, count);
		}
	}
	if ((pf->dot == 0 && pf->nul == 1) || (pf->spec == 'f' && pf->nul == 1))
		ft_type_sp_nul(pf->wid, count);
	else
		ft_type_nul(pf->prec, count);
	ft_putstr_pf(num, count);
}
