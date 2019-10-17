/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:10:02 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/21 20:32:58 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(t_pf *pf, char *new_pnt, int pnt, int *count)
{
	if (pf->minus)
	{
		ft_putstr_pf("0x", count);
		ft_type_nul(pf->prec, count);
		if (!(pf->dot && pf->prec == 0 && pnt == 0))
			ft_putstr_pf(new_pnt, count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		ft_type_space(pf->wid, count);
		ft_putstr_pf("0x", count);
		ft_type_nul(pf->prec, count);
		if (!(pf->dot && pf->prec == 0 && pnt == 0))
			ft_putstr_pf(new_pnt, count);
	}
}

void	ft_pointer(va_list ap, int *count, t_pf *pf)
{
	long long	pnt;
	char		*new_pnt;
	int			len;

	pnt = va_arg(ap, long long);
	new_pnt = ft_convert_v_16(pnt, pf);
	len = ft_strlen(new_pnt);
	if (pf->dot && pf->prec == 0 && pnt == 0)
		pf->wid++;
	pf->prec = (((pf->prec - len) < 0) ? 0 : (pf->prec - len));
	pf->wid = (((pf->wid - (pf->prec + len + 2)) < 0 ? 0 :
		(pf->wid - (pf->prec + len + 2))));
	ft_print_pointer(pf, new_pnt, pnt, count);
	free(new_pnt);
}

void	ft_percent(int *count, t_pf *pf)
{
	pf->wid--;
	if (pf->minus)
	{
		ft_putchar_pf('%', count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		(pf->nul != 0) ? (ft_type_sp_nul(pf->wid, count)) :
		(ft_type_space(pf->wid, count));
		ft_putchar_pf('%', count);
	}
}

t_pf	*ft_create_struct_printf(void)
{
	t_pf	*temp;

	if ((temp = (t_pf *)malloc(sizeof(t_pf))) == NULL)
		return (NULL);
	ft_initialization(temp);
	return (temp);
}

void	ft_initialization(t_pf *temp)
{
	temp->dot = 0;
	temp->znak = 0;
	temp->spec = 0;
	temp->resh = 0;
	temp->j = 0;
	temp->z = 0;
	temp->hh = 0;
	temp->h = 0;
	temp->ll = 0;
	temp->l = 0;
	temp->minus = 0;
	temp->plus = 0;
	temp->space = 0;
	temp->nul = 0;
	temp->bl = 0;
	temp->ml = 0;
	temp->procent = 0;
	temp->wid = 0;
	temp->prec = 0;
}
