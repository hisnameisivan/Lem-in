/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 20:52:49 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/23 21:13:53 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_modul_char(char *num)
{
	ft_memmove(num, (num + 1), ft_strlen(num + 1) + 1);
}

void		ft_cmp_wid_prec_num(t_pf *pf, char *num)
{
	int		count;

	if ((pf->spec == 'd' || pf->spec == 'i' || pf->spec == 'f')
	&& ft_strchr(num, '-'))
	{
		pf->znak = -1;
		ft_modul_char(num);
	}
	else if ((pf->spec == 'd' || pf->spec == 'i') && !(ft_strchr(num, '-')))
		pf->znak = 1;
	count = ft_strlen(num);
	if ((pf->spec == 'o') && pf->resh == 1)
	{
		pf->prec--;
		pf->wid--;
	}
	pf->prec = ((pf->prec - count < 0) ? 0 : (pf->prec - count));
	((pf->wid - (pf->prec + count)) < 0) ? (pf->wid = 0) :
	(pf->wid = pf->wid - (pf->prec + count));
	if ((pf->plus && (pf->spec == 'd' || pf->spec == 'i' || pf->spec == 'f')) ||
	((pf->spec == 'd' || pf->spec == 'i' || pf->spec == 'f')
	&& (pf->znak == -1)))
		(((pf->wid) - 1) > 0) ? ((pf->wid)--) : (pf->wid = 0);
	if (((pf->spec == 'x') || (pf->spec == 'X')) && (pf->resh == 1))
		pf->wid = ((pf->wid - 2 > 0) ? pf->wid - 2 : 0);
}

long long	ft_apply_modificator(va_list ap, t_pf *pf)
{
	long long	num;

	num = va_arg(ap, long long);
	if (pf->h)
		(pf->spec == 'd' || pf->spec == 'i') ? (num = (short)num)
		: (num = (unsigned short)num);
	else if (pf->hh)
		(pf->spec == 'd' || pf->spec == 'i') ? (num = (char)num) :
		(num = (unsigned char)num);
	else if (pf->l)
		(pf->spec == 'd' || pf->spec == 'i') ? (num = (long)num) :
		(num = (unsigned long)num);
	else if (pf->ll)
		(pf->spec == 'd' || pf->spec == 'i') ? (num = (long long)num) :
		(num = (unsigned long long)num);
	else if (pf->j)
		num = (uintmax_t)num;
	else if (pf->z)
		num = (size_t)num;
	return (num);
}
