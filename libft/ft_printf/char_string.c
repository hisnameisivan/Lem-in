/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 21:54:58 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/21 21:34:00 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(va_list ap, int *count, t_pf *pf)
{
	char	ch;

	ch = (char)va_arg(ap, int);
	pf->wid = pf->wid - 1;
	if (pf->minus)
	{
		ft_putchar_pf(ch, count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		(pf->nul == 1) ? ft_type_sp_nul(pf->wid, count) :
		ft_type_space(pf->wid, count);
		ft_putchar_pf(ch, count);
	}
}

void	ft_char_2(char p, int *count, t_pf *pf)
{
	char	ch;

	ch = p;
	pf->wid = pf->wid - 1;
	if (pf->minus)
	{
		ft_putchar_pf(ch, count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		(pf->nul == 1) ? ft_type_sp_nul(pf->wid, count) :
		ft_type_space(pf->wid, count);
		ft_putchar_pf(ch, count);
	}
}

void	ft_print_string(t_pf *pf, char *str, int *count)
{
	if (pf->minus)
	{
		while (pf->prec-- > 0 && *str != '\0')
			ft_putchar_pf(*str++, count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		(pf->nul == 1) ? ft_type_sp_nul(pf->wid, count) :
		ft_type_space(pf->wid, count);
		while (pf->prec-- > 0 && *str != '\0')
			ft_putchar_pf(*str++, count);
	}
}

void	ft_string(va_list ap, int *count, t_pf *pf)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (*str == '\0')
	{
		ft_type_space(pf->wid, count);
		return ;
	}
	len = ft_strlen(str);
	if (pf->dot == 0)
		pf->prec = len;
	if (pf->prec > len)
		pf->prec = len;
	pf->wid = ((pf->wid - pf->prec <= 0) ? 0 : (pf->wid - pf->prec));
	ft_print_string(pf, str, count);
}
